#include <iostream>

#include "unixstreamsocket.h"

socketlib::UnixStreamSocket::UnixStreamSocket(int fd,
                                              int protocol)
    : socket_domain(AF_UNIX),
      socket_type(Socket::stream_socket),
      socket_protocol(protocol),
      socket_path("")
{
    socket_addr.sun_family = socket_domain;
    if (fd >= 0) {
        socket_fd = fd;
    }else{
        socket_fd = socket(socket_domain, socket_type, socket_protocol);
    }
}

socketlib::UnixStreamSocket::~UnixStreamSocket()
{
    close(socket_fd);
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

int socketlib::UnixStreamSocket::connectTo(std::string path)
{
    socket_path = path;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    return connect(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}

void socketlib::UnixStreamSocket::sendData(const char *data)
{
    write(socket_fd, data, sizeof(data));
}

char* socketlib::UnixStreamSocket::readBuffer()
{
    read(socket_fd, buffer, 20);
    return buffer;
}
