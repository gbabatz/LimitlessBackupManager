set(TARGET_NAME file_copy)

# Define sources
set(SOURCES
    FileCopy.cpp
)

set(HEADERS
    FileCopy.hpp
)

# Create library
add_library(${TARGET_NAME} ${SOURCES} ${HEADERS})

# Make it easy to link against the whole core
add_library(LBM::Core::FileCopy ALIAS ${TARGET_NAME})

# Include directories
target_include_directories(${TARGET_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Install library (for production builds)
install(TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${PROD_BINARIES_PATH}
    ARCHIVE DESTINATION ${PROD_BINARIES_PATH}
)