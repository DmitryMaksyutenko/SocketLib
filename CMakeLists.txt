cmake_minimum_required(VERSION 3.10)

project(socketlib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED Unix/socket.cpp
                                    Unix/unixstreamsocket.cpp
                                    Unix/unixdatagramsocket.cpp
                                    Unix/unixserverstreamsocket.cpp
                                    Inet/inetdatagramsocet.cpp)
