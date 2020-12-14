#ifndef UNIXSOCKET_H
#define UNIXSOCKET_H

#include <sys/un.h>

#include "socket.h"

namespace socketlib {

class UnixSocket : public Socket
{
private:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    std::string socket_path;
    sockaddr_un socket_addr;

public:
    UnixSocket(const std::string path, int type, int protocol = 0);
    ~UnixSocket();

    void makeItServer() override;

    int domain() override;
    int type() override;
    int protocol() override;
    const std::string fullPath() override;


};

}

#endif // UNIXSOCKET_H
