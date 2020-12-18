#include "unixdatagramsocket.h"

socketlib::UnixDatagramSocket::UnixDatagramSocket(const std::string path, int protocol)
    : socket_domain(AF_UNIX),
      socket_type(Socket::datagram_socket),
      socket_protocol(protocol),
      socket_path(path)
{
    socket_addr.sun_family = socket_domain;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    socket_fd = socket(socket_domain, socket_type, socket_protocol);
}

socketlib::UnixDatagramSocket::~UnixDatagramSocket()
{
    close(socket_fd);
}

int socketlib::UnixDatagramSocket::domain()
{
    return socket_domain;
}

int socketlib::UnixDatagramSocket::type()
{
    return socket_type;
}

int socketlib::UnixDatagramSocket::protocol()
{
    return socket_protocol;
}

const std::string socketlib::UnixDatagramSocket::fullPath()
{
    return socket_path;
}

int socketlib::UnixDatagramSocket::connectTo()
{
    return connect(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}
