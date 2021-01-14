#include "socketinet.h"

socketlib::SocketInet::SocketInet(std::string host,
                          std::string port,
                          int type,
                          int protocol,
                          int fd)

    : socket_type(type),
      socket_protocol(protocol),
      socket_host(host),
      socket_port(port)
{
    constructSocket(fd);
}

void socketlib::SocketInet::constructSocket(int fd)
{
    if (fd >= 0) {
        socket_fd = fd;
    }else{
        socket_addr.ai_family = AF_UNSPEC;
        socket_addr.ai_socktype = socket_type;
        socket_addr.ai_flags = AI_PASSIVE;
        socket_addr.ai_protocol = socket_protocol;
        socket_addr.ai_canonname = NULL;
        socket_addr.ai_addr = NULL;
        socket_addr.ai_next = NULL;
        findAddresLoop();
    }
}

void socketlib::SocketInet::findAddresLoop()
{

    addrinfo * result, *rp;
    getaddrinfo(socket_host.c_str(), socket_port.c_str(), &socket_addr, &result);

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        socket_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (socket_fd == -1) {
            continue;
        }
        if (bind(socket_fd, rp->ai_addr, rp->ai_addrlen) == 0) {
            break;
        }

        close(socket_fd);
    }

    freeaddrinfo(result); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
}

socketlib::SocketInet::~SocketInet()
{
   close(socket_fd);

}

int socketlib::SocketInet::domain()
{
    return socket_domain;
}

int socketlib::SocketInet::type()
{
    return socket_type;
}

int socketlib::SocketInet::protocol()
{
    return socket_protocol;
}

int socketlib::SocketInet::socketDesctiptor()
{
    return socket_fd;
}

std::string socketlib::SocketInet::fullPath()
{
    pid_t pid = getpid();
    std::string fullPath = "/proc/" + std::to_string(pid) +
                            "/fd/" + std::to_string(socket_fd);
    return fullPath;
}
