#include "inetdatagramsocet.h"


socketlib::InetDatagramSocet::InetDatagramSocet(std::string path,
                                                int protocol,
                                                int fd)
    : Socket(AF_INET, SOCK_DGRAM, protocol, fd, path.c_str())
{
    remove(path.c_str());
    sockaddr_in a;
    memset(&a, 0, sizeof (a));
    a.sin_addr.s_addr = inet_addr("127.0.0.1");
    a.sin_family = socket_domain;
    memcpy(&socket_addr, &a, sizeof (a));
    bind(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}

socketlib::InetDatagramSocet::~InetDatagramSocet()
{

}
