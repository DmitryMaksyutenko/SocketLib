#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

#include <string>

namespace socketlib  {

class Socket
{

public:
    static const int stream_socket;
    static const int datagram_socket;

    virtual ~Socket() {};

    virtual int domain() = 0;
    virtual int type() = 0;
    virtual int protocol() = 0;
    virtual const std::string fullPath() = 0;


};

const int Socket::stream_socket = SOCK_STREAM;
const int Socket::datagram_socket = SOCK_DGRAM;

}


#endif // SOCKET_H
