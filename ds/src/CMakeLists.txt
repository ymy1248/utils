link_libraries(${Boost_LIBRARIES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

set(DS_SRCS trie.cpp disjoint_set.cpp)
set(DS_HDRS list.hpp trie.hpp vector.hpp deque.hpp tree.hpp graph.hpp disjoint_set.hpp)
# set(EXPORT_HDRS list.hpp)

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/ymy_pkgs)
add_library(ymy_ds STATIC ${DS_SRCS} ${DS_HDRS})

install(TARGETS ymy_ds
        LIBRARY DESTINATION utils_ds
        ARCHIVE DESTINATION utils_ds_static)
install(FILES ${DS_HDRS} DESTINATION utils_ds_include)

message(${CMAKE_INSTALL_PREFIX})