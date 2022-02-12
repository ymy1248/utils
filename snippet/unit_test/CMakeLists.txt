cmake_minimum_required(VERSION 3.14)

link_libraries(${GTEST_BOTH_LIBRARIES})
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_binary_search test_binary_search.cpp)

gtest_discover_tests(test_binary_search test_binary_search)