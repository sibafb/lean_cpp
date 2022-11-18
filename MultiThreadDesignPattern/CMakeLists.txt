cmake_minimum_required(VERSION 3.0.2)

project(MultiThreadDesignPattern)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(SingleThreadExecution SingleThreadExecution.cpp)
add_executable(Immutable Immutable.cpp)
add_executable(GuardedSuspension GuardedSuspension.cpp)

target_link_libraries(SingleThreadExecution PRIVATE Threads::Threads)
target_link_libraries(Immutable PRIVATE Threads::Threads)
target_link_libraries(GuardedSuspension PRIVATE Threads::Threads)