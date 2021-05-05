find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
add_executable(test_trie test_trie.cpp)
target_link_libraries(test_trie ${GTEST_BOTH_LIBRARIES} ymy_ds)

include(GoogleTest)

gtest_discover_tests(test_trie)