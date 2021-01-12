#ifndef TST_INETSOCK_H
#define TST_INETSOCK_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../Inet/inetdatagramsocet.h"

using namespace testing;
namespace fs = std::filesystem;

std::string test_url = "127.0.0.1";

TEST(InetSocket, InetDatagramSocket)
{
    socketlib::InetDatagramSocet soc(test_url);
}

#endif // TST_INETSOCK_H
