cmake_minimum_required(VERSION 3.14)

# Set the project name and version
project(LBM VERSION 0.1 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Build configuration
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Build mode selection (default to Release)
set(BUILD_MODE "RELEASE" CACHE STRING "Build mode: RELEASE, DEBUG, or TEST")
set_property(CACHE BUILD_MODE PROPERTY STRINGS "RELEASE" "DEBUG" "TEST")

# Install paths - organized under build/ with mode-specific subdirectories
set(INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build/install)
if(BUILD_MODE STREQUAL "RELEASE")
    set(INSTALL_SUBDIR "release")
elseif(BUILD_MODE STREQUAL "DEBUG")
    set(INSTALL_SUBDIR "debug")
elseif(BUILD_MODE STREQUAL "TEST")
    set(INSTALL_SUBDIR "test")
endif()

set(PROD_BINARIES_PATH ${INSTALL_PREFIX}/${INSTALL_SUBDIR}/bin)
set(DEBUG_BINARIES_PATH ${INSTALL_PREFIX}/${INSTALL_SUBDIR}/debug)
set(TEST_BINARIES_PATH ${INSTALL_PREFIX}/${INSTALL_SUBDIR}/tests)
set(MOCK_BINARIES_PATH ${INSTALL_PREFIX}/${INSTALL_SUBDIR}/mocks)

# add logging library
find_package(spdlog REQUIRED)
add_library(build_common_libs INTERFACE)
target_link_libraries(build_common_libs INTERFACE spdlog::spdlog)

# Include appropriate configuration
if(BUILD_MODE STREQUAL "RELEASE")
    include(cm-release.cmake)
elseif(BUILD_MODE STREQUAL "DEBUG")
    include(cm-debug.cmake)
elseif(BUILD_MODE STREQUAL "TEST")
    set(GTEST_BUILD "LOCAL" CACHE STRING "GoogleTest build method: FETCH, LOCAL, or DEPS")
    include(cm-tests.cmake)
else()
    message(FATAL_ERROR "Invalid BUILD_MODE: ${BUILD_MODE}. Must be RELEASE, DEBUG, or TEST")
endif()
