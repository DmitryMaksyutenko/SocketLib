#ifndef INETDATAGRAMSOCET_H
#define INETDATAGRAMSOCET_H

#include "socketinet.h"

namespace socketlib {


class InetDatagramSocet : public SocketInet
{
public:
    InetDatagramSocet(std::string addr,
                      std::string port,
                      int protocol = 0,
                      int fd = -1);
    ~InetDatagramSocet();

};

}

#endif // INETDATAGRAMSOCET_H
