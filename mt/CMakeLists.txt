project(MT)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src
                    ${CMAKE_SOURCE_DIR}/ds/src)
 
link_libraries(util ${GTEST_BOTH_LIBRARIES} ymy_ds)

add_executable(mutex mutex.cpp)
add_executable(atomic atomic.cpp)
add_executable(thread thread.cpp)
add_executable(thread_local thread_local.cpp)

gtest_discover_tests(mutex mutex)
gtest_discover_tests(thread thread)
gtest_discover_tests(atomic atomic)
gtest_discover_tests(thread_local thread_local)