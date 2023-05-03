cmake_minimum_required(VERSION 3.7.0)
project(problem79)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/libs")
set(THREADS_PREFER_PTHREAD_FLAG ON)
include_directories(${LIBS_PATH}/ZipLib)

find_package(Threads REQUIRED)

add_subdirectory(${LIBS_PATH}/ZipLib ZipLib)


add_executable(problem79 problem79.cpp)
target_link_libraries(problem79 PUBLIC ZipLib)
target_link_libraries(problem79 PUBLIC "-pthread")

