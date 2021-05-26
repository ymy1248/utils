cmake_minimum_required(VERSION 3.14)
project(LEARN_OS)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/ymy_pkgs)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-pthread -std=c++14")

add_executable(mmap mmap.cpp)