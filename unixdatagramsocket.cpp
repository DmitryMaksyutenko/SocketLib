#include "unixdatagramsocket.h"

#include <iostream>

socketlib::UnixDatagramSocket::UnixDatagramSocket(std::string path,
                                                  int protocol,
                                                  int fd)
    : Socket(AF_UNIX, SOCK_DGRAM, protocol, fd, path.c_str())
{
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    bind(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}

socketlib::UnixDatagramSocket::~UnixDatagramSocket()
{
    close(socket_fd);
    unlink(socket_path.c_str());
}

size_t socketlib::UnixDatagramSocket::receiveFrom(const Socket &source)
{
    sockaddr_un addr = source.socketAddres();
    socklen_t len = sizeof (addr);
    size_t size = recvfrom(socket_fd, buffer, 20, 0,
                           (sockaddr *)&addr, &len);
    return size;
}

size_t socketlib::UnixDatagramSocket::sendTo(const Socket &dest)
{
    sockaddr_un addr = dest.socketAddres();
    socklen_t len = sizeof (addr);
    char buff[5] = {'a', 'b', 'c', 'd', 'e'};
    size_t size = sendto(socket_fd, buff, 5, 0,
                         (sockaddr *)&addr, len);
    return size;
}

