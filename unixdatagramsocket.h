#ifndef UNIXDATAGRAMSOCKET_H
#define UNIXDATAGRAMSOCKET_H


#include "socket.h"

namespace socketlib {

class UnixDatagramSocket : public Socket
{

public:
    UnixDatagramSocket(int protocol = 0,
                       int fd = -1);
    ~UnixDatagramSocket();

    int connectTo(std::string path);

};

}

#endif // UNIXDATAGRAMSOCKET_H
