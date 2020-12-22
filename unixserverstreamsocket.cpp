#include "unixserverstreamsocket.h"

socketlib::UnixServerStreamSocket::UnixServerStreamSocket(const std::string path, int maxConnections, int protocol)
    : socket_domain(AF_UNIX),
      socket_type(Socket::stream_socket),
      socket_protocol(protocol),
      socket_path(path)
{
    socket_addr.sun_family = socket_domain;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    socket_fd = socket(socket_domain, socket_type, socket_protocol);
    bind( socket_fd, (sockaddr *) &socket_addr, sizeof(socket_addr));
    listen(socket_fd, maxConnections);
}

socketlib::UnixServerStreamSocket::~UnixServerStreamSocket()
{
    close(socket_fd);
    unlink(socket_path.c_str());
}
int socketlib::UnixServerStreamSocket::domain()
{
    return socket_domain;
}

int socketlib::UnixServerStreamSocket::type()
{
    return socket_type;
}

int socketlib::UnixServerStreamSocket::protocol()
{
    return socket_protocol;
}

const std::string socketlib::UnixServerStreamSocket::fullPath()
{
    return socket_path;
}

socketlib::UnixStreamSocket socketlib::UnixServerStreamSocket::acceptConnection()
{
    int clientFd = accept(socket_fd, 0, 0);

    UnixStreamSocket peerSoc(clientFd);
    return peerSoc;
}
