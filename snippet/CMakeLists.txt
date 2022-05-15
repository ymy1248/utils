project(snippet)

link_libraries(${GTEST_BOTH_LIBRARIES})
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(unit_test)

add_executable(sort sort.cpp)