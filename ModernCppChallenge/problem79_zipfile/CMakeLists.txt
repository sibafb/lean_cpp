cmake_minimum_required(VERSION 3.7.0)
project(problem79)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/include")
set(LIBS_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/libs")
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(SUBMODULE_PROJETCT_PATH "${CMAKE_SOURCE_DIR}/../The-Modern-Cpp-Challenge/Chapter10/problem_79")

include_directories(${LIBS_PATH}/ZipLib)

find_package(Threads REQUIRED)

add_subdirectory(${LIBS_PATH}/ZipLib ZipLib)


add_executable(problem79 problem79.cpp)
target_link_libraries(problem79 PUBLIC ZipLib)
target_link_libraries(problem79 PUBLIC "-pthread")

add_custom_command(TARGET problem79 PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${SUBMODULE_PROJETCT_PATH}/sample79.zip $<TARGET_FILE_DIR:problem79>)

add_custom_command(TARGET problem79 PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${SUBMODULE_PROJETCT_PATH}/sample79.zip ${CMAKE_CURRENT_BINARY_DIR})