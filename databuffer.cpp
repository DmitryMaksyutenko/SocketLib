#include <cstring>

#include "databuffer.h"


socketlib::DataBuffer::DataBuffer(int readSize, int writeSize)
{
    read.reserve(readSize);
    write.reserve(writeSize);
    writePosition = write.begin();
    readPosition = read.begin();
}

socketlib::DataBuffer::~DataBuffer()
{
}

int socketlib::DataBuffer::readBufferSize() const
{
    return read.capacity();
}

int socketlib::DataBuffer::writeBufferSize() const
{
    return write.capacity();
}

void socketlib::DataBuffer::appendWrite(const char *data)
{
    const char *dataEnd = data + strlen(data);
    write.insert(writePosition, data, dataEnd);
    writePosition += strlen(data);
}

void socketlib::DataBuffer::appendRead(const char *data)
{
    const char *dataEnd = data + strlen(data);
    read.insert(readPosition, data, dataEnd);
    readPosition += strlen(data);
}

char *socketlib::DataBuffer::writeBuffer()
{
    return write.data();
}

char *socketlib::DataBuffer::readBuffer()
{
    return read.data();
}

int socketlib::DataBuffer::countWrite() const
{
    return write.size();
}

int socketlib::DataBuffer::countRead() const
{
    return read.size();
}
