cmake_minimum_required(VERSION 3.0.2)

find_package(Threads REQUIRED)

project(threadClass)

set(CMAKE_CXX_FLAGS "-std=c++17 -pthread")

add_executable(${PROJECT_NAME}
    threadClass.cpp
	)

target_link_libraries(${PROJECT_NAME} Threads::Threads)