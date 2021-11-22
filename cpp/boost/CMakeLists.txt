find_package(Boost REQUIRED COMPONENTS system serialization)
link_libraries(${Boost_LIBRARIES})
add_executable(dynamic_bitset dynamic_bitset.cpp)
add_executable(archive archive.cpp)