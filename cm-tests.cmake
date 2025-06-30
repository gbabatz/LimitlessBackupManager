cmake_minimum_required(VERSION 3.14)

message(STATUS "Configuring TEST build")

# Set build type (tests need debug info)
set(CMAKE_BUILD_TYPE Debug)

# Debug flags for tests
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")

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

    FetchContent_MakeAvailable(googletest)
else()
    add_subdirectory(dependencies/googletest-1.17.0)
endif()

add_library(test_common INTERFACE)
target_compile_definitions(test_common INTERFACE GTEST) # in code macro
target_link_libraries(test_common INTERFACE gtest gmock gtest_main)

# Enable CTest
# enable_testing()

# Build both source and tests
add_subdirectory(tests)
# add_subdirectory(src)