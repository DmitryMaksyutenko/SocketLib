#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include <cstring>
#include <string>

namespace socketlib  {

class SocketInet
{
protected:
    int socket_domain;
    int socket_type;
    int socket_protocol;
    int socket_fd;
    addrinfo socket_addr;
    std::string socket_host;
    std::string socket_port;

public:

    SocketInet(std::string host,
               std::string port,
               int type,
               int protocol = 0,
               int fd = -1);
    virtual ~SocketInet();

    virtual int domain();
    virtual int type();
    virtual int protocol();
    virtual int socketDesctiptor();
    virtual std::string fullPath();
    virtual std::string address();

    friend bool operator==(const SocketInet &lhs, const SocketInet &rhs)
    {
        return lhs.socket_fd == rhs.socket_fd;
    }

private:
    void constructSocket(int fd);
    void findAddresLoop();

};

}


#endif // SOCKET_H
