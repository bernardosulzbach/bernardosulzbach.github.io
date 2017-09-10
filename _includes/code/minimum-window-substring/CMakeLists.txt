cmake_minimum_required (VERSION 2.8)

project (solution)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic -Wall")

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Required because of old GCC.
add_definitions (-std=c++11)

add_executable (solution main.cpp)
