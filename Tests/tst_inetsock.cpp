#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../Inet/inetdatagramsocet.h"

using namespace testing;
namespace fs = std::filesystem;

std::string test_addr = "127.0.0.1";
std::string server_port = "60999";

TEST(InetSocket, InetDatagramSocket)
{
    std::string data = "some";
    socketlib::InetDatagramSocet soc(test_addr, server_port);
    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
    ASSERT_EQ(test_addr, soc.address());
}
