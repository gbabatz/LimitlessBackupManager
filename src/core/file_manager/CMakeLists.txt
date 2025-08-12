set(TARGET_NAME file_manager)

# Define sources
set(SOURCES
    FileManager.cpp
    CopyDirectoryContents.cpp
)

set(HEADERS
    FileManager.hpp
    CopyDirectoryContents.hpp
)

# Create library
add_library(${TARGET_NAME} ${SOURCES} ${HEADERS})

# Make it easy to link against the whole core
add_library(LBM::Core::FileManager ALIAS ${TARGET_NAME})

# Include directories
target_include_directories(${TARGET_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Install library (for production builds)
install(TARGETS ${TARGET_NAME}
    LIBRARY DESTINATION ${PROD_BINARIES_PATH}
    ARCHIVE DESTINATION ${PROD_BINARIES_PATH}
)