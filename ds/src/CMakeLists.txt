set(DS_SRCS trie.cpp)
set(DS_HDRS list.hpp trie.hpp vector.hpp)

add_library(ymy_ds STATIC ${DS_SRCS} ${DS_HDRS})

install(TARGETS ymy_ds
        LIBRARY DESTINATION ds)
