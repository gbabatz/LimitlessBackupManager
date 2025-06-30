cmake_minimum_required(VERSION 3.14)

message(STATUS "Configuring TEST build")

# Set build type (tests need debug info)
set(CMAKE_BUILD_TYPE Debug)

# Debug flags for tests
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")

# Build both source and tests
add_subdirectory(src)
add_subdirectory(tests)

# Enable CTest
enable_testing()