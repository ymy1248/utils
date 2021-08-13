# cmake_minimum_required(VERSION 3.14)
project(CPP)

link_libraries(util)

message("CPP project begins!")
message(${YMY_UTILS_GLOBAL})

add_subdirectory(template)
add_subdirectory(basic)
add_subdirectory(boost)