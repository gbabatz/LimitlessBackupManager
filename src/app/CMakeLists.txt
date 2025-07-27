# No need for cmake_minimum_required in subdirectories
set(TARGET_NAME lbm-main)  # Use lowercase for consistency

# Collect sources (avoid GLOB for better dependency tracking)
set(SOURCES main.cpp)

# Create executable
add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE build_common_libs)

# Set properties
set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME "lbm"  # Final executable name
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install
install(TARGETS ${TARGET_NAME} 
    RUNTIME DESTINATION ${PROD_BINARIES_PATH}
)