cmake_minimum_required(VERSION 3.0.2)

project(fmt_learn)

set(CMAKE_CXX_FLAGS "-std=c++17")

add_subdirectory(../../ModernCppChallenge/fmt fmt)

add_executable(fmt_learn ${CMAKE_CURRENT_SOURCE_DIR}/fmt.cpp)
target_link_libraries(fmt_learn fmt::fmt)