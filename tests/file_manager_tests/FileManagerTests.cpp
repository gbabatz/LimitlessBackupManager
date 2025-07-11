/**
 * @file FileCopyTests.cpp
 * @brief Unit tests for FileCopy module.
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#include "gtest/gtest.h"
// #include "gmock/gmock.h"

#include "FileManager.hpp"

#include <filesystem>
#include <string>
#include <memory>
#include <fstream>

using namespace ::testing;

class FileManagerFixture : public Test {
protected:
  std::unique_ptr<FileManager> fileManager_ptr;

  void SetUp() override {
    // Setup code if needed
    fileManager_ptr = std::make_unique<FileManager>();
  }

  void TearDown() override {
    // Cleanup code if needed
    fileManager_ptr.reset();

  }
};

TEST_F(FileManagerFixture, CopyFile) {
  
  std::string source = "test_source.txt";
  std::string destination = "test_destination.txt";

  // Create a test file
  std::ofstream(source) << "Test content";

  // Perform the copy operation
  bool result = fileManager_ptr->CopyFile(source, destination);

  // Check if the copy was successful
  EXPECT_TRUE(result);
  
  // Verify the destination file exists and has the correct content
  std::ifstream destFile(destination);
  std::string content((std::istreambuf_iterator<char>(destFile)),
                      std::istreambuf_iterator<char>());
  
  EXPECT_EQ(content, "Test content");

  // Clean up test files
  std::filesystem::remove(source);
  std::filesystem::remove(destination);
}