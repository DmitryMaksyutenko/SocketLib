#include "unixstreamsocket.h"

socketlib::UnixStreamSocket::UnixStreamSocket(const std::string path, int protocol)
    : socket_domain(AF_UNIX),
      socket_type(Socket::stream_socket),
      socket_protocol(protocol),
      socket_path(path)
{
    socket_addr.sun_family = socket_domain;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    socket_fd = socket(socket_domain, socket_type, socket_protocol);
//    bind( socket_fd, (sockaddr *) &socket_addr, sizeof(socket_addr));
}

socketlib::UnixStreamSocket::~UnixStreamSocket()
{
    close(socket_fd);
//    unlink(socket_path.c_str());
}

int socketlib::UnixStreamSocket::domain()
{
    return socket_domain;
}

int socketlib::UnixStreamSocket::type()
{
    return socket_type;
}

int socketlib::UnixStreamSocket::protocol()
{
    return socket_protocol;
}

const std::string socketlib::UnixStreamSocket::fullPath()
{
    return socket_path;
}

int socketlib::UnixStreamSocket::connectTo()
{
    return connect(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}
