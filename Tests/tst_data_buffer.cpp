#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../SocketLib/databuffer.h"

using namespace testing;

TEST(DataBuffer, DataBufferTest)
{
    int read = 2048;
    int write = 2048;
    std::string toSend = "some string to send";
    socketlib::DataBuffer buffer(read, write);

    ASSERT_EQ(read, buffer.readBufferSize());
    ASSERT_EQ(write, buffer.writeBufferSize());

    buffer.appendWrite(toSend.c_str());
    ASSERT_EQ(toSend, buffer.writeBuffer());

    buffer.appendRead(toSend.c_str());
    ASSERT_EQ(toSend, buffer.readBuffer());
    ASSERT_EQ(toSend.size(), buffer.countRead());
    ASSERT_EQ(toSend.size(), buffer.countWrite());
}
