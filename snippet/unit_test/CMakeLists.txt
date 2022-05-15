cmake_minimum_required(VERSION 3.14)


add_executable(test_binary_search test_binary_search.cpp)

gtest_discover_tests(test_binary_search test_binary_search)