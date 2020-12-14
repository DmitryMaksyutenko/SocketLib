#ifndef TST_LIBTESTS_H
#define TST_LIBTESTS_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "unixsocket.h"

using namespace testing;
namespace fs = std::filesystem;

const std::string un_soc_1 = "/Sockets/un_soc_1";

class UnixSocketFixture : public ::testing::Test
{

protected:
    int type;
    int protocol;
    fs::path file_path;
    socketlib::UnixSocket *soc;

    void SetUp() override
    {
        type = socketlib::Socket::stream_socket;
        protocol = 0;
        file_path = un_soc_1;
        soc = new socketlib::UnixSocket(un_soc_1, type, protocol);
    }

    void TearDown() override
    {
        delete soc;
    }

};

TEST_F(UnixSocketFixture, UnixSocketTest)
{
    ASSERT_EQ(AF_UNIX, soc->domain());
    ASSERT_EQ(type, soc->type());
    ASSERT_EQ(protocol, soc->protocol());
    ASSERT_EQ(file_path, soc->fullPath());
}

TEST_F(UnixSocketFixture, UnixSocketAsServerTest)
{
    soc->makeItServer();
    ASSERT_TRUE(fs::exists(file_path));
}

#endif // TST_LIBTESTS_H
