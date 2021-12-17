link_libraries(${Boost_LIBRARIES})
include_directories( ${Boost_INCLUDE_DIRS})

set(DS_SRCS trie.cpp)
set(DS_HDRS list.hpp trie.hpp vector.hpp deque.hpp tree.hpp)
# set(EXPORT_HDRS list.hpp)

# set(CMAKE_INSTALL_PREFIX $ENV{HOME}/ymy_pkgs)
add_library(ymy_ds STATIC ${DS_SRCS} ${DS_HDRS})

install(TARGETS ymy_ds
        LIBRARY DESTINATION utils_ds
        ARCHIVE DESTINATION utils_ds_static)
install(FILES ${DS_HDRS} DESTINATION utils_ds_include)
install(FILES ${EXPORT_HDRS} DESTINATION utils_ds_include)

message(${CMAKE_INSTALL_PREFIX})