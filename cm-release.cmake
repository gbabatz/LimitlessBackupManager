cmake_minimum_required(VERSION 3.14)

message(STATUS "Configuring RELEASE build")

# Set build type
set(CMAKE_BUILD_TYPE Release)

# Release-specific compiler flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Build optimized production code
add_subdirectory(src)