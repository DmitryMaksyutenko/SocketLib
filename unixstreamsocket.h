#ifndef UNIXSOCKET_H
#define UNIXSOCKET_H


#include "socket.h"

namespace socketlib {

class UnixStreamSocket : public Socket
{

    // test field.
    char buffer[20];

public:
    UnixStreamSocket(int fd = -1,
                     int protocol = 0);
    ~UnixStreamSocket();

    int connectTo(std::string path);
    void sendData(const char *data);
    const char* readBuffer();

};

}

#endif // UNIXSOCKET_H
