#include "unixstreamsocket.h"

socketlib::UnixStreamSocket::UnixStreamSocket(int fd,
                                              int protocol)
    : Socket(AF_UNIX, SOCK_STREAM, protocol, fd)
{
}

socketlib::UnixStreamSocket::~UnixStreamSocket()
{
    close(socket_fd);
}

int socketlib::UnixStreamSocket::connectTo(std::string path)
{
    socket_path = path;
    strncpy(socket_addr.sun_path, path.c_str(), sizeof(socket_addr.sun_path) - 1);
    return connect(socket_fd, (sockaddr *)&socket_addr, sizeof(socket_addr));
}

void socketlib::UnixStreamSocket::sendData(const char *data)
{
    write(socket_fd, data, strlen(data));
}

const char* socketlib::UnixStreamSocket::readBuffer()
{
    int readed = read(socket_fd, buffer, 20);
    buffer[readed] = '\0';
    return buffer;
}
