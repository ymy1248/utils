project(MT)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)
 
link_libraries(util ${GTEST_BOTH_LIBRARIES})

add_executable(mutex mutex.cpp)
add_executable(thread_fance thread_fance.cpp)
add_executable(atomic atomic.cpp)
add_executable(thread thread.cpp)

gtest_discover_tests(mutex mutex)
gtest_discover_tests(thread thread)
gtest_discover_tests(atomic atomic)