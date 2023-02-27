cmake_minimum_required(VERSION 3.0.2)

project(chrono)

set(CMAKE_CXX_FLAGS "-std=c++17")

add_executable(${PROJECT_NAME}
    chrono.cpp
)

