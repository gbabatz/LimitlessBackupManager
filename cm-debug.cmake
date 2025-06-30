cmake_minimum_required(VERSION 3.14)

message(STATUS "Configuring DEBUG build") 

# Set build type
set(CMAKE_BUILD_TYPE Debug)

# Debug-specific compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")

# Build production code with debug symbols
add_subdirectory(src)