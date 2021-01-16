cmake_minimum_required(VERSION 3.5)

project(LibTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "/home/dima/googletest" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "/home/dima/googletest")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

get_filename_component(PARENT_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

include_directories(${GTestIncludes}
                    ${PARENT_DIR}/lib
                    ${PARENT_DIR})

add_executable(LibTests main.cpp
               tst_unixsock.h
               tst_inetsock.cpp
               tst_data_buffer.cpp
               ${GTestFiles})

add_test(NAME UnixStreamSocketTest COMMAND UnixStreamSocketTest)
add_test(NAME UnixDatagramSocketTest COMMAND UnixDatagramSocketTest)
add_test(NAME UnixServerSocketTest COMMAND UnixmServerSocketTest)
add_test(NAME UnixSocketStreamConnectionTest COMMAND UnixSocketStreamConnectionTest)
add_test(NAME UnixSocketDatagramSendingTest COMMAND UnixSocketDatagramSendingTest)

add_test(NAME InetDatagramSocket COMMAND InetDatagramSocket)

add_test(NAME DataBufferTest COMMAND DataBufferTest)

target_link_libraries(LibTests PRIVATE Threads::Threads ${PARENT_DIR}/lib/libsocketlib.so)

