cmake_minimum_required(VERSION 3.0.2)

project(ModernCppChallenge)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(problem1 problem1.cpp)
add_executable(problem2 problem2.cpp)
add_executable(problem15 problem15.cpp)
add_executable(problem16 problem16.cpp)
add_executable(problem17 problem17.cpp)
add_executable(problem18 problem18.cpp)
add_executable(problem19 problem19.cpp)
# add_executable(problem20 problem20.cpp) ##cannot build for find function.
add_executable(problem22 problem22.cpp)
add_executable(problem23 problem23.cpp)
add_executable(problem24 problem24.cpp)
add_executable(problem25 problem25.cpp)
add_executable(problem26 problem26.cpp)
add_executable(problem27 problem27.cpp)
add_executable(problem28 problem28.cpp)
add_executable(problem29 problem29.cpp)
add_executable(problem30 problem30.cpp)
add_executable(problem31 problem31.cpp)
add_executable(problem32 problem32.cpp)
