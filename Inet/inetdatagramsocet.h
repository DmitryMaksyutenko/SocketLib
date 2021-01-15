#ifndef INETDATAGRAMSOCET_H
#define INETDATAGRAMSOCET_H

#include "socketinet.h"

namespace socketlib {


class InetDatagramSocet : public SocketInet
{
private:
    addrinfo peer_soc;
    char inBuffer[1024];
    char outBuffer[1024];

public:
    InetDatagramSocet(std::string addr,
                      std::string port,
                      int protocol = 0,
                      int fd = -1);
    ~InetDatagramSocet();

    size_t receiveData();
    size_t sendTo(const char *host, const char *port, const char *data);

private:
    addrinfo *constructAddres(const char *host, const char *port);
};

}

#endif // INETDATAGRAMSOCET_H
