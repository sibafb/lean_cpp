cmake_minimum_required(VERSION 3.20.1)
project(problem43_fmt)

set(CMAKE_CXX_FLAGS "-std=c++17")

find_package(Threads REQUIRED)

find_package(Boost 1.56 REQUIRED COMPONENTS
             date_time filesystem iostreams)

add_subdirectory(../fmt fmt)

add_executable(problem43_fmt ${CMAKE_CURRENT_SOURCE_DIR}/problem43_fmt.cpp)
target_link_libraries(problem43_fmt fmt::fmt Boost::date_time Boost::filesystem Boost::iostreams)
