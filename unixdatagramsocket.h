#ifndef UNIXDATAGRAMSOCKET_H
#define UNIXDATAGRAMSOCKET_H


#include "socket.h"

namespace socketlib {

class UnixDatagramSocket : public Socket
{
    char buffer[20];

public:
    UnixDatagramSocket(std::string path,
                       int protocol = 0,
                       int fd = -1);
    ~UnixDatagramSocket();

    size_t receiveFrom(const Socket &source);
    size_t sendTo(const Socket &dest);
};

}

#endif // UNIXDATAGRAMSOCKET_H
