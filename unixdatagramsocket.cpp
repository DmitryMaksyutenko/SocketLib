#include "unixdatagramsocket.h"

socketlib::UnixDatagramSocket::UnixDatagramSocket(int protocol,
                                                  int fd)
    : Socket(AF_UNIX, SOCK_DGRAM, protocol, fd)
{
}

socketlib::UnixDatagramSocket::~UnixDatagramSocket()
{
    close(socket_fd);
}

int socketlib::UnixDatagramSocket::connectTo(std::string path)
{
    socket_path = path;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    return connect(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}
