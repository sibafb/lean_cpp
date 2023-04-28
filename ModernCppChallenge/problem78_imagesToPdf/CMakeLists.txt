cmake_minimum_required(VERSION 3.0.2)

project(problem78)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/libs")

#Refer to the path set as a sub-module.
set(SUBMODULE_PROJETCT_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/Chapter09/problem_78")

include_directories(${LIBS_PATH}/ZipLib)
include_directories(${LIBS_PATH}/PDF-Writer)
include_directories(${LIBS_PATH}/PDF-Writer/FreeType/include)
include_directories(${INCLUDE_PATH})

add_subdirectory(${LIBS_PATH}/ZipLib ZipLib)
add_subdirectory(${LIBS_PATH}/PDF-Writer PDF-Writer)

add_executable(problem78 problem78.cpp)
target_link_libraries(problem78 ZipLib)
target_link_libraries(problem78 PDFWriter)
target_link_libraries(problem78 FreeType)
target_link_libraries(problem78 LibAesgm)
target_link_libraries(problem78 LibJpeg)
target_link_libraries(problem78 LibPng)
target_link_libraries(problem78 LibTiff)
target_link_libraries(problem78 Zlib)

add_custom_command(TARGET problem78 PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${SUBMODULE_PROJETCT_PATH}/res $<TARGET_FILE_DIR:problem78>/res)

add_custom_command(TARGET problem78 PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${SUBMODULE_PROJETCT_PATH}/res ${CMAKE_CURRENT_BINARY_DIR}/res)