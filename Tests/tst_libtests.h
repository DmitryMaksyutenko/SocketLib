#ifndef TST_LIBTESTS_H
#define TST_LIBTESTS_H

#include <filesystem>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "unixsocket.h"

using namespace testing;

TEST(LibTests, UnixSocketTest)
{
    namespace fs = std::filesystem;
    int domen = socketlib::Socket::unix_domain;
    int type = socketlib::Socket::stream_socket;
    int protocol = 0;
    fs::path file_path;
    socketlib::UnixSocket soc(domen, type);

    ASSERT_EQ(domen, soc.Domain());
    ASSERT_EQ(type, soc.Type());
    ASSERT_EQ(protocol, soc.Protocol());
}

#endif // TST_LIBTESTS_H
