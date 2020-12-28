#include "unixdatagramsocket.h"

#include <iostream>

socketlib::UnixDatagramSocket::UnixDatagramSocket(std::string path,
                                                  int protocol,
                                                  int fd)
    : Socket(AF_UNIX, SOCK_DGRAM, protocol, fd, path.c_str())
{
    remove(path.c_str());
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    bind(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}

socketlib::UnixDatagramSocket::~UnixDatagramSocket()
{
    close(socket_fd);
    unlink(socket_path.c_str());
}

size_t socketlib::UnixDatagramSocket::receiveFrom()
{
    sockaddr_un addr;
    socklen_t len = sizeof (addr);
    size_t size = recvfrom(socket_fd, buffer, 20, 0,
                           (sockaddr *)&addr, &len);
    return size;
}

size_t socketlib::UnixDatagramSocket::sendTo(const char *dest, const char *data)
{
    sockaddr_un addr = constructAddres(dest);
    socklen_t len = sizeof (addr);
    size_t size = sendto(socket_fd, data, strlen(data), 0,
                         (sockaddr *)&addr, len);
    std::cout << size << " " << addr.sun_path << std::endl;
    return size;
}

const char *socketlib::UnixDatagramSocket::data()
{
    return buffer;
}

sockaddr_un socketlib::UnixDatagramSocket::constructAddres(const char *path)
{
    sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, path, sizeof(addr.sun_path) - 1);

    return addr;
}

