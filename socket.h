#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>

#include <string>

namespace socketlib  {

class Socket
{
protected:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    std::string socket_path;
    sockaddr_un socket_addr;

public:

    Socket(int domain,
           int type,
           int protocol = 0,
           int fd = -1,
           const char *path = "");
    virtual ~Socket();

    virtual int domain();
    virtual int type();
    virtual int protocol();
    virtual const std::string fullPath();

private:
    void constructSocketAddr(int fd);

};

}


#endif // SOCKET_H
