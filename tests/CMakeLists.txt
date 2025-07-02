set(TARGET_NAME sample-tests)  # Use lowercase for consistency

# Collect test sources (avoid GLOB for better dependency tracking)
set(TEST_SOURCES
    sample_tests.cpp
    # Add more
)

# Create executable
add_executable(${TARGET_NAME} ${TEST_SOURCES})

# Link with our common test interface
target_link_libraries(${TARGET_NAME} PRIVATE test_common)

target_compile_definitions(${TARGET_NAME} PRIVATE PROJECT_ROOT="${PROJECT_ROOT}")

# Set properties
set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME "sample-tests"  # Final executable name
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Register tests with CTest
gtest_discover_tests(${TARGET_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} # Ensure tests run in the correct directory
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
# TIP: the WORKING_DIRECTORY property tells CTest "when you run this test, 
# simulate as if you are calling the binarary from this directory"

# Install
install(TARGETS ${TARGET_NAME}
    RUNTIME DESTINATION ${TEST_BINARIES_PATH}
)