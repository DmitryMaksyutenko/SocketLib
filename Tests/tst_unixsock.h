#ifndef TST_LIBTESTS_H
#define TST_LIBTESTS_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "Unix/unixstreamsocket.h"
#include "Unix/unixdatagramsocket.h"
#include "Unix/unixserverstreamsocket.h"

using namespace testing;
namespace fs = std::filesystem;

const std::string un_str_soc = "/Sockets/un_str_soc";
const std::string un_dgr_soc = "/Sockets/un_dgr_soc";
const char *test_data = "Some data\n";

class DatagramSocketMock : public socketlib::UnixDatagramSocket
{
public:
    DatagramSocketMock(std::string path) : socketlib::UnixDatagramSocket(path){};
    MOCK_METHOD(size_t, receiveFrom, ());
    MOCK_METHOD(size_t, sendTo, (const Socket &source, const char * data));
};


TEST(UnixSocket, UnixStreamSocketTest)
{
    socketlib::UnixStreamSocket soc;

    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_STREAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ("", soc.fullPath());
    ASSERT_EQ(-1, soc.connectTo(un_str_soc));
}

TEST(UnixSocket, UnixDatagramSocketTest)
{
    socketlib::UnixDatagramSocket soc(un_dgr_soc);

    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_DGRAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ(un_dgr_soc, soc.fullPath());
    ASSERT_TRUE(fs::exists(soc.fullPath()));
    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
}

TEST(UnixSocket, UnixStreamServerSocketTest)
{
    socketlib::UnixServerStreamSocket soc(un_str_soc);

    ASSERT_EQ(AF_UNIX, soc.domain());
    ASSERT_EQ(SOCK_STREAM, soc.type());
    ASSERT_EQ(0, soc.protocol());
    ASSERT_EQ(un_str_soc, soc.fullPath());
    ASSERT_TRUE(fs::exists(soc.fullPath()));
    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
}

TEST(UnixSocket, UnixSocketStreamConnectionTest)
{
    socketlib::UnixServerStreamSocket server(un_str_soc);
    socketlib::UnixStreamSocket client;

    ASSERT_EQ(0, client.connectTo(un_str_soc));
    ASSERT_EQ(typeid(server.acceptConnection()).name(),
              typeid(client).name());
}

TEST(UnixSocket, UnixSocketDataSending)
{
    socketlib::UnixServerStreamSocket server(un_str_soc);
    socketlib::UnixStreamSocket clientSender;

    clientSender.connectTo(un_str_soc);
    socketlib::UnixStreamSocket clientReceiver = server.acceptConnection();

    clientSender.sendData(test_data);
    const char *data = clientReceiver.readBuffer();

    ASSERT_STREQ(data, test_data);
}

TEST(UnixSocket, UnixSocketDatagramSendingTest)
{
    std::string path_1 = "/Sockets/soc_1";
    std::string path_2 = "/Sockets/soc_2";

    DatagramSocketMock mockSocetRcv(path_1);
    DatagramSocketMock mockSocetSend(path_2);

    EXPECT_CALL(mockSocetSend, sendTo(mockSocetRcv, test_data))
            .Times(AtLeast(1));
    EXPECT_CALL(mockSocetRcv, receiveFrom())
            .Times(AtLeast(1));
    mockSocetRcv.receiveFrom();
    mockSocetSend.sendTo(mockSocetRcv, test_data);

}

#endif // TST_LIBTESTS_H
