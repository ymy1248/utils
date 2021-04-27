set(DS_SRCS trie.cpp)
set(DS_HDRS list.hpp trie.hpp vector.hpp)

# set(CMAKE_INSTALL_PREFIX $ENV{HOME})
add_library(ymy_ds SHARED ${DS_SRCS} ${DS_HDRS})

install(TARGETS ymy_ds
        LIBRARY DESTINATION ymy_lib
        ARCHIVE DESTINATION ymy_lib)

message("Finished src")
message(${CMAKE_INSTALL_PREFIX})
