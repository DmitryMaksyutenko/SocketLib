#include "unixsocket.h"

socketlib::UnixSocket::UnixSocket(const std::string path, int type, int protocol)
    : socket_domain(AF_UNIX),
      socket_type(type),
      socket_protocol(protocol),
      socket_path(path)
{
    socket_addr.sun_family = socket_domain;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    socket_fd = socket(socket_domain, socket_type, socket_protocol);
}

socketlib::UnixSocket::~UnixSocket()
{
    close(socket_fd);
    unlink(socket_path.c_str());
}

void socketlib::UnixSocket::makeItServer()
{
    bind(
        socket_fd,
        (sockaddr *) &socket_addr,
        sizeof(socket_addr)
    );
}

int socketlib::UnixSocket::domain()
{
    return socket_domain;
}

int socketlib::UnixSocket::type()
{
    return socket_type;
}

int socketlib::UnixSocket::protocol()
{
    return socket_protocol;
}

const std::string socketlib::UnixSocket::fullPath()
{
    return socket_path;
}
