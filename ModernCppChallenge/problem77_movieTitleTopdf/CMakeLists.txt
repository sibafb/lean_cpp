cmake_minimum_required(VERSION 3.7.0)

project(problem77)

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/libs")

include_directories(${LIBS_PATH}/ZipLib)
include_directories(${LIBS_PATH}/PDF-Writer)
include_directories(${LIBS_PATH}/PDF-Writer/FreeType/include)
include_directories(${INCLUDE_PATH})

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

add_subdirectory(${LIBS_PATH}/ZipLib ZipLib)
add_subdirectory(${LIBS_PATH}/PDF-Writer PDF-Writer)

add_executable(problem77 problem77.cpp)
target_link_libraries(problem77 ZipLib)
target_link_libraries(problem77 PDFWriter)
target_link_libraries(problem77 FreeType)
target_link_libraries(problem77 LibAesgm)
target_link_libraries(problem77 LibJpeg)
target_link_libraries(problem77 LibPng)
target_link_libraries(problem77 LibTiff)
target_link_libraries(problem77 Zlib)
