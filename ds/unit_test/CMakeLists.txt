find_package(GTest REQUIRED)
find_package(Boost REQUIRED COMPONENTS timer)
include_directories(${GTEST_INCLUDE_DIRS})
# set(CMKE_CXX_FLAGS "-lboost_timer")
# set(Boost_USE_STATIC_LIBS OFF) 
# set(Boost_USE_MULTITHREADED ON) 

if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost Not found")
endif()

enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src ${Boost_INCLUDE_DIR})
link_libraries(${GTEST_BOTH_LIBRARIES} ${Boost_LIBRARIES} ymy_ds)

add_executable(test_trie test_trie.cpp)
add_executable(test_vector test_vector.cpp)
add_executable(test_list test_list.cpp)
add_executable(test_tree test_tree.cpp)

include(GoogleTest)

gtest_discover_tests(test_trie)
gtest_discover_tests(test_vector)
gtest_discover_tests(test_list)
