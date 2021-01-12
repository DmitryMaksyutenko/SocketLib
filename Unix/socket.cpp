#include "socket.h"

socketlib::Socket::Socket(int domain,
                          int type,
                          int protocol,
                          int fd,
                          const char *path)
    : socket_domain(domain),
      socket_type(type),
      socket_protocol(protocol),
      socket_path(path)
{
    constructSocket(fd);
}

void socketlib::Socket::constructSocket(int fd)
{
    socket_addr.sun_family = socket_domain;
    if (fd >= 0) {
        socket_fd = fd;
    }else{
        socket_fd = socket(socket_domain, socket_type, socket_protocol);
    }
}

socketlib::Socket::~Socket()
{
   close(socket_fd);
}

int socketlib::Socket::domain()
{
    return socket_domain;
}

int socketlib::Socket::type()
{
    return socket_type;
}

int socketlib::Socket::protocol()
{
    return socket_protocol;
}

int socketlib::Socket::socketDesctiptor()
{
    return socket_fd;
}

sockaddr_un socketlib::Socket::socketAddres() const
{
    return socket_addr;
}

const std::string socketlib::Socket::fullPath()
{
    return socket_path;
}
