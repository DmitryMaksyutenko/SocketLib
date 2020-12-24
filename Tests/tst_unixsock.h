#ifndef TST_LIBTESTS_H
#define TST_LIBTESTS_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "unixstreamsocket.h"
#include "unixdatagramsocket.h"
#include "unixserverstreamsocket.h"

using namespace testing;
namespace fs = std::filesystem;

const std::string un_soc_1 = "/Sockets/un_soc_1";
const char *test_data = "Some data\n";


TEST(UnixSocket, UnixStreamSocketTest)
{
    socketlib::UnixStreamSocket soc;
    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_STREAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ("", soc.fullPath());
    ASSERT_EQ(-1, soc.connectTo(un_soc_1));
}

TEST(UnixSocket, UnixDatagramSocketTest)
{
    socketlib::UnixDatagramSocket soc;
    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_DGRAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ("", soc.fullPath());
    ASSERT_EQ(-1, soc.connectTo(un_soc_1));
}

TEST(UnixSocket, UnixStreamServerSocketTest)
{
    socketlib::UnixServerStreamSocket soc(un_soc_1, 1);
    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_STREAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ(un_soc_1, soc.fullPath());
    ASSERT_TRUE(fs::exists(soc.fullPath()));
    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
}

TEST(UnixSocket, UnixSocketConnectionTest)
{
    socketlib::UnixServerStreamSocket server(un_soc_1, 0);
    socketlib::UnixStreamSocket client;

    ASSERT_EQ(0, client.connectTo(un_soc_1));
    ASSERT_EQ(typeid(server.acceptConnection()).name(),
              typeid(client).name());
}

TEST(UnixSocket, UnixSocketDataSending)
{
    socketlib::UnixServerStreamSocket server(un_soc_1, 0);
    socketlib::UnixStreamSocket clientSender;

    clientSender.connectTo(un_soc_1);
    socketlib::UnixStreamSocket clientReceiver = server.acceptConnection();

    clientSender.sendData(test_data);
    const char *data = clientReceiver.readBuffer();

    ASSERT_STREQ(data, test_data);
}

#endif // TST_LIBTESTS_H
