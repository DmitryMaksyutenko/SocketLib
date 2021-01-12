#ifndef INETDATAGRAMSOCET_H
#define INETDATAGRAMSOCET_H

#include "socket.h"

namespace socketlib {


class InetDatagramSocet : public Socket
{
public:
    InetDatagramSocet(std::string path,
                      int protocol = 0,
                      int fd = -1);
    ~InetDatagramSocet();
};

}

#endif // INETDATAGRAMSOCET_H
