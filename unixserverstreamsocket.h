#ifndef UNIXSERVERSTREAMSOCKET_H
#define UNIXSERVERSTREAMSOCKET_H

#include "socket.h"
#include "unixstreamsocket.h"

namespace socketlib {

class UnixServerStreamSocket : public Socket
{

public:
    UnixServerStreamSocket(const std::string path,
                           int maxConnections = 0,
                           int protocol = 0);
    ~UnixServerStreamSocket();

    UnixStreamSocket acceptConnection();
};

}

#endif // UNIXSERVERSTREAMSOCKET_H
