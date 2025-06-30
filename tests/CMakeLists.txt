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

# Set properties
set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME "sample-tests"  # Final executable name
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# # Register tests with CTest
# include(GoogleTest)
# gtest_discover_tests(${TARGET_NAME}
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
# )

# Install
install(TARGETS ${TARGET_NAME}
    RUNTIME DESTINATION ${TEST_BINARIES_PATH}
)