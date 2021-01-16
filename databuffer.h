#ifndef DATABUFFER_H
#define DATABUFFER_H

#include <vector>
#include <iterator>

namespace socketlib {


class DataBuffer
{
private:
    std::vector<char> read;
    std::vector<char> write;
    std::vector<char>::iterator writePosition;
    std::vector<char>::iterator readPosition;

public:
    DataBuffer(int readSize = 1024, int writeSize = 1024);
    ~DataBuffer();

    int readBufferSize() const;
    int writeBufferSize() const;

    void appendWrite(const char *data);
    void appendRead(const char *data);
    char *writeBuffer();
    char *readBuffer();
    int countWrite() const;
    int countRead() const;
};

}

#endif // DATABUFFER_H
