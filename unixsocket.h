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

public:
    UnixSocket(char *path, int domain, int type, int protocol = 0);
    ~UnixSocket();

    int domain() override;
    int type() override;
    int protocol() override;
    std::string fullPath() override;
    std::filesystem::path stdFileSystemPath() override;

};

}

#endif // UNIXSOCKET_H
