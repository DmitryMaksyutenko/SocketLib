#ifndef UNIXDATAGRAMSOCKET_H
#define UNIXDATAGRAMSOCKET_H


#include "../socket.h"

namespace socketlib {

class UnixDatagramSocket : public Socket
{
    char buffer[20];

public:
    UnixDatagramSocket(std::string path,
                       int protocol = 0,
                       int fd = -1);
    ~UnixDatagramSocket();

    size_t receiveFrom();
    size_t sendTo(const char *dest, const char* data);
    const char *data();

private:
    sockaddr_un constructAddres(const char *path);
};

}

#endif // UNIXDATAGRAMSOCKET_H
