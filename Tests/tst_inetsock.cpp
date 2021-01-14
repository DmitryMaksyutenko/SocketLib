#ifndef TST_INETSOCK_H
#define TST_INETSOCK_H

#include <filesystem>
#include <iostream>

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
    socketlib::InetDatagramSocet soc(test_addr, server_port);
    ASSERT_TRUE(fs::is_socket(soc.fullPath()));
}

#endif // TST_INETSOCK_H
