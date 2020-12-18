#ifndef UNIXDATAGRAMSOCKET_H
#define UNIXDATAGRAMSOCKET_H


#include "socket.h"

namespace socketlib {

class UnixDatagramSocket : public Socket
{

private:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    std::string socket_path;
    sockaddr_un socket_addr;

public:
    UnixDatagramSocket(const std::string path, int protocol = 0);
    ~UnixDatagramSocket();

    int domain() override;
    int type() override;
    int protocol() override;
    const std::string fullPath() override;

    int connectTo();

};

}

#endif // UNIXDATAGRAMSOCKET_H
