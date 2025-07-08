cmake_minimum_required(VERSION 3.14)

message(STATUS "Configuring TEST build")

# Set build type (tests need debug info)
set(CMAKE_BUILD_TYPE Debug)

# Debug flags for tests
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")

# Add library for test utilities
add_library(test_common INTERFACE)

if(GTEST_BUILD STREQUAL "FETCH")
    set(USE_FETCH_CONTENT ON CACHE BOOL "Use modern CMake features like FetchContent")
    if (USE_FETCH_CONTENT)
        # Modern approach: Use FetchContent instead of add_subdirectory for external deps
        include(FetchContent) # load and execute another CMake file within the current scope

        # Option 1: Use FetchContent (recommended for newer CMake)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        v1.17.0
        )

        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        
        FetchContent_MakeAvailable(googletest) # the name here must match the one in FetchContent_Declare
    endif()
elseif(GTEST_BUILD STREQUAL "LOCAL")
    # Local installation of GoogleTest - assumes it's installed in /usr/local
    target_include_directories(test_common INTERFACE /usr/local/include)
    target_link_directories(test_common INTERFACE /usr/local/lib/gtest /usr/local/lib/gmock)
elseif(GTEST_BUILD STREQUAL "DEPS")
    # Use local copy of GoogleTest in the dependencies directory
    add_subdirectory(dependencies/googletest-1.17.0)
else()
    message(FATAL_ERROR "Invalid GTEST_BUILD: ${GTEST_BUILD}. Must be FETCH, LOCAL, or DEPS")
endif()

target_compile_definitions(test_common INTERFACE GTEST) # in code macro
target_link_libraries(test_common INTERFACE gtest gmock gtest_main)

# Enable CTest
enable_testing()

# Load GoogleTest CMake functions, i.e. gtest_discover_tests(...)
include(GoogleTest) # Looks for Googletest.cmake Module

# Build both source and tests
add_subdirectory(tests)
# add_subdirectory(src)