project(MT)

link_libraries(util)

add_executable(mutex mutex.cpp)
add_executable(thread_fance thread_fance.cpp)
add_executable(atomic atomic.cpp)