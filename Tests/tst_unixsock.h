#ifndef TST_LIBTESTS_H
#define TST_LIBTESTS_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "unixstreamsocket.h"
#include "unixdatagramsocket.h"

using namespace testing;
namespace fs = std::filesystem;

const std::string un_soc_1 = "/Sockets/un_soc_1";


TEST(UnixSocket, UnixStreamSocketTest)
{
    socketlib::UnixStreamSocket soc(un_soc_1);
    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(socketlib::UnixStreamSocket::stream_socket, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ(un_soc_1, soc.fullPath());
    ASSERT_EQ(-1, soc.connectTo());
//    ASSERT_TRUE(fs::exists(soc.fullPath()));
//    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
}

TEST(UnixSocket, UnixDatagramSocketTest)
{
    socketlib::UnixDatagramSocket soc(un_soc_1);
    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(socketlib::Socket::datagram_socket, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ(un_soc_1, soc.fullPath());
    ASSERT_EQ(-1, soc.connectTo());
}

#endif // TST_LIBTESTS_H
