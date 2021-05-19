find_package(Boost REQUIRED COMPONENTS timer)

include_directories(${Boost_INCLUDE_DIR})

add_executable(template_method template_method.cpp)
add_executable(observer observer.cpp)

message("Finished design")
message(${CMAKE_INSTALL_PREFIX})
