#include "inetdatagramsocet.h"


socketlib::InetDatagramSocet::InetDatagramSocet(std::string addr,
                                                std::string port,
                                                int protocol,
                                                int fd)
    : SocketInet(addr, port, SOCK_DGRAM, protocol, fd)
{

}

socketlib::InetDatagramSocet::~InetDatagramSocet()
{

}

size_t socketlib::InetDatagramSocet::receiveData()
{
    sockaddr_un addr;
    socklen_t len = sizeof (addr);
    size_t size = recvfrom(socket_fd, buffer.readBuffer(), buffer.readBufferSize(), 0,
                           (sockaddr *)&addr, &len);
    return size;
}

size_t socketlib::InetDatagramSocet::sendTo(const char *host, const char *port, const char *data)
{
    addrinfo *addr = constructAddres(host, port);
    socklen_t len = sizeof (addr);
    buffer.appendWrite(data);
    size_t size = sendto(socket_fd, buffer.writeBuffer(), buffer.writeBufferSize(), 0,
                         (sockaddr *)addr, len);
//    freeaddrinfo(addr);
    return size;
}

addrinfo *socketlib::InetDatagramSocet::constructAddres(const char *host, const char *port)
{
    addrinfo hint, *res;
    hint.ai_socktype = AF_UNSPEC;
    hint.ai_family = SOCK_DGRAM;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = NULL;
    hint.ai_flags = AI_NUMERICSERV;

    getaddrinfo(host, port, &hint, &res);

    return res;
}
