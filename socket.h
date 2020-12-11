#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <unistd.h>

#include <string>
#include <filesystem>

namespace socketlib  {

class Socket
{

public:
    static int unix_domain;
    static int stream_socket;
    static int datagram_socket;

    virtual ~Socket() {};

    virtual int domain() = 0;
    virtual int type() = 0;
    virtual int protocol() = 0;
    virtual std::string fullPath();
    virtual std::filesystem::path stdFileSystemPath();

};

int Socket::unix_domain = AF_UNIX;
int Socket::stream_socket = SOCK_STREAM;
int Socket::datagram_socket = SOCK_DGRAM;

}


#endif // SOCKET_H
