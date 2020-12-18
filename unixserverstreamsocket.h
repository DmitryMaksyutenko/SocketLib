#ifndef UNIXSERVERSTREAMSOCKET_H
#define UNIXSERVERSTREAMSOCKET_H

#include "socket.h"

namespace socketlib {

class UnixServerStreamSocket : public Socket
{
private:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    std::string socket_path;
    sockaddr_un socket_addr;

public:
    UnixServerStreamSocket(const std::string path, int maxConnections, int protocol = 0);
    ~UnixServerStreamSocket();

    int domain() override;
    int type() override;
    int protocol() override;
    const std::string fullPath() override;
};

}

#endif // UNIXSERVERSTREAMSOCKET_H
