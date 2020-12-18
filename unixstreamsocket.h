#ifndef UNIXSOCKET_H
#define UNIXSOCKET_H


#include "socket.h"

namespace socketlib {

class UnixStreamSocket : public Socket
{

private:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    std::string socket_path;
    sockaddr_un socket_addr;

public:
    UnixStreamSocket(const std::string path, int protocol = 0);
    ~UnixStreamSocket();

    int domain() override;
    int type() override;
    int protocol() override;
    const std::string fullPath() override;

    int connectTo();
};

}

#endif // UNIXSOCKET_H
