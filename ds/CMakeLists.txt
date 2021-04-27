cmake_minimum_required(VERSION 3.14)
project(DS)

set(CMAKE_INSTALL_PREFIX $ENV{HOME})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14")

add_subdirectory(src)
add_subdirectory(unit_test)
