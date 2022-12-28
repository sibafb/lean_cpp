cmake_minimum_required(VERSION 3.0.2)

project(ModernCppChallenge)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(problem1 problem1.cpp)
add_executable(problem2 problem2.cpp)
