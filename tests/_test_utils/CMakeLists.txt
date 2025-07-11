set(TARGET_NAME test_utils)

# Define sources
set(SOURCES
    TestUtils.cpp
)

set(HEADERS
    TestUtils.hpp
)

# Create library
add_library(${TARGET_NAME} ${SOURCES} ${HEADERS})

# Make it easy to link against the whole core
add_library(LBM::Tests::TestUtils ALIAS ${TARGET_NAME})

target_compile_definitions(${TARGET_NAME} PRIVATE PROJECT_ROOT="${PROJECT_ROOT}")

# Include directories
target_include_directories(${TARGET_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Install library (for production builds)
install(TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${PROD_BINARIES_PATH}
    ARCHIVE DESTINATION ${PROD_BINARIES_PATH}
)