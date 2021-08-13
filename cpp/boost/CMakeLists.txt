find_package(Boost REQUIRED COMPONENTS system serialization)
add_executable(dynamic_bitset dynamic_bitset.cpp)
add_executable(archive archive.cpp)
target_link_libraries(archive ${Boost_LIBRARIES})