#include "unixsocket.h"

socketlib::UnixSocket::UnixSocket(char *path, int domain, int type, int protocol)
{
    socket_domain = domain;
    socket_type = type;
    socket_protocol = protocol;

    socket_fd = socket(socket_domain, socket_type, socket_protocol);
}

socketlib::UnixSocket::~UnixSocket()
{
    close(socket_fd);
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

std::string socketlib::UnixSocket::fullPath()
{

}

std::filesystem::__cxx11::path socketlib::UnixSocket::stdFileSystemPath()
{

}
