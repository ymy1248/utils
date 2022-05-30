project(snippet)

link_libraries(${GTEST_BOTH_LIBRARIES})
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(unit_test)

add_executable(sort sort.cpp)
add_executable(knapsack knapsack.cpp)
add_executable(dijkstra dijkstra.cpp)

gtest_discover_tests(sort sort)
gtest_discover_tests(knapsack knapsack)