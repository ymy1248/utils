# cmake_minimum_required(VERSION 3.14)
project(CPP)

include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
link_libraries(util ${GTEST_BOTH_LIBRARIES})

add_subdirectory(template)
add_subdirectory(basic)
add_subdirectory(boost)