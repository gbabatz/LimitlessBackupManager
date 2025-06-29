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

# Install paths
set(INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build/install)
set(PROD_BINARIES_PATH ${INSTALL_PREFIX}/bin)
set(TEST_BINARIES_PATH ${INSTALL_PREFIX}/tests)
set(MOCK_BINARIES_PATH ${INSTALL_PREFIX}/mocks)

# Build type selection
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    include(cm-tests.cmake)
else()
    include(cm-production.cmake)
endif()

#set(CMAKE_BUILD_RPATH ${MOCK_BINARIES_PATH})
#list(APPEND CMAKE_INSTALL_RPATH ${MOCK_BINARIES_PATH})