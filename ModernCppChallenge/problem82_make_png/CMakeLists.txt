cmake_minimum_required(VERSION 3.7.0)
project(problem82)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/libs")

include_directories(${LIBS_PATH}/PDF-Writer/LibPng)
include_directories(${LIBS_PATH}/PDF-Writer/ZLib)
include_directories(${LIBS_PATH}/PDF-Writer/FreeType/include)
include_directories(${LIBS_PATH}/PNGWriter)

add_subdirectory(${LIBS_PATH}/ZipLib ZipLib)

add_executable(problem82 problem82.cpp)

target_link_libraries(problem82 LibPng)
target_link_libraries(problem82 Zlib)
target_link_libraries(problem82 FreeType)
target_link_libraries(problem82 PNGWriter)


