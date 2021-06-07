cmake_minimum_required(VERSION 3.14)
project(DS)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/ymy_pkgs)
set(CMAKE_CXX_STANDARD 14)

# set(CMAKE_CXX_FLAGS "-lboost_timer -lgtest_main -lgtest -pthread -std=c++14")
set(CMAKE_CXX_FLAGS "-pthread -std=c++14")

add_subdirectory(src)
add_subdirectory(unit_test)