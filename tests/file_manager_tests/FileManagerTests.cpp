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
#include "TestUtils.hpp"

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

namespace fs = std::filesystem;

using namespace ::testing;

class FileManagerFixture : public Test {
protected:
  std::unique_ptr<FileManager> fileManager_ptr;

  void SetUp() override {
    // Setup code if needed
    fileManager_ptr = std::make_unique<FileManager>();
    TestUtils::CreateSandboxDirectories(TestUtils::SANDBOX_PATH);
    fs::current_path(TestUtils::SANDBOX_PATH);
  }

  void TearDown() override {
    // Cleanup code if needed
    fileManager_ptr.reset();
    TestUtils::FinalizeDirectories(TestUtils::SANDBOX_PATH);
  }
};

TEST_F(FileManagerFixture, CreateManager) {
  // Check if the FileManager instance is created successfully
  EXPECT_TRUE(fileManager_ptr != nullptr);
  EXPECT_TRUE(dynamic_cast<FileManager *>(fileManager_ptr.get()) != nullptr);
}

TEST_F(FileManagerFixture, CopyFile_Success) {

  std::string test_file = "test_file.txt";
  std::string test_file_source = TestUtils::SRC_PATH + "/" + test_file;
  std::string test_file_dest = TestUtils::DEST_PATH + "/" + test_file;

  std::string test_file_sample_txt = "This is a test file.";

  std::ofstream(test_file_source) << test_file_sample_txt;

  // Perform the copy operation
  bool result =
      fileManager_ptr->CopyFile(test_file_source, TestUtils::DEST_PATH);

  // Check if the copy was successful
  EXPECT_TRUE(result);

  // Verify the test_file_dest file exists and has the correct content
  std::ifstream destFile(test_file_dest);
  std::string content((std::istreambuf_iterator<char>(destFile)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(content, test_file_sample_txt);
}