#ifndef SRC_CORE_FILE_MANAGER_DRAFT_HPP
#define SRC_CORE_FILE_MANAGER_DRAFT_HPP

#include <filesystem>
#include <map>
#include <string>

enum class CopyMethod { DEFAULT, RECURSIVE, DIRS_STRUCTURE };
extern std::map<CopyMethod, std::filesystem::copy_options> copyOptionsMap;

bool CopyDirectoryContents(const std::string &src_dir,
                           const std::string &dst_dir,
                           const CopyMethod &copy_method);

#endif // SRC_CORE_FILE_MANAGER_DRAFT_HPP