/**
 * @file FileManager.hpp
 * @brief
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

// #include "IFileManager.hpp"

#include <string>
#include <vector>

class FileManager {
public:
  FileManager() = default;
  virtual ~FileManager() = default;

  virtual bool CopyFile(const std::string &source,
                        const std::string &destination);
  virtual bool MoveFile(const std::string &source,
                        const std::string &destination);
  virtual bool DeleteFile(const std::string &path);

  virtual bool CopyDirectory(const std::string &source,
                             const std::string &destination);

private:
  virtual std::vector<std::string>
  ListFilesInDirectory(const std::string &directory) const;

  virtual bool FileExists(const std::string &path) const;

  std::vector<std::string> mFilesInDirectory;
};

#endif // FILEMANAGER_HPP