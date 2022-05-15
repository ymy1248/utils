cmake_minimum_required(VERSION 3.14)
project(YMY_UTILS)

enable_testing()

# add_compile_options(-Wall -Werror)

set(YMY_UTILS_GLOBAL "utils global")

# set(CMAKE_C_COMPILER "/usr/bin/clang") 
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_INSTALL_PREFIX $ENV{HOME}/ymy_pkgs)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-pthread")

find_package(GTest REQUIRED)
include_directories(util/src)

add_subdirectory(cpp)
add_subdirectory(design)
add_subdirectory(ds)
add_subdirectory(os)
add_subdirectory(util)
add_subdirectory(mt)
add_subdirectory(snippet)
# add_subdirectory(profile)