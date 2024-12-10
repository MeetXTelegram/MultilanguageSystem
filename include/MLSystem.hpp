#pragma once

#include <string>

#include <User.hpp>

namespace mlsys {
    namespace FilesStorage {
        std::string getFilesPath();
    }

    std::string castLanguageToFilename(User)

    std::string getReplic(const std::string& file, const std::string& section, const std::string& replic);
}
