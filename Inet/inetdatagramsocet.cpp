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
