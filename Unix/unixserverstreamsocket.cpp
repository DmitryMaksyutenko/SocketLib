#include "unixserverstreamsocket.h"

socketlib::UnixServerStreamSocket::UnixServerStreamSocket(const std::string path,
                                                          int maxConnections,
                                                          int protocol)
    : Socket(AF_UNIX,
             SOCK_STREAM,
             protocol,
             -1,
             path.c_str())
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

socketlib::UnixStreamSocket socketlib::UnixServerStreamSocket::acceptConnection()
{
    int clientFd = accept(socket_fd, 0, 0);

    UnixStreamSocket peerSoc(clientFd);
    return peerSoc;
}
