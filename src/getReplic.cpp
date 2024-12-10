#include <MLSystem.hpp>

#include <csignal>
#include <filesystem>
#include <fstream>

#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

std::string mlsys::getReplic(const std::string& file, const std::string& section, const std::string& replic) {
    if (file.empty() || section.empty() || replic.empty()) {
        spdlog::get("MLSystem")->log(spdlog::level::warn, "The file, section, or replica is not specified");
        return "If you see this text, the getReplic call was incorrect(the file, section, or replica is not specified)";
    }

    if (!std::filesystem::exists(file)) {
        spdlog::get("MLSystem")->log(spdlog::level::warn, "The translation file was not found");
        return "If you see this text, the getReplic call was incorrect(the translation file was not found)";
    }

    std::ifstream jsonFile(file);
    if (jsonFile.is_open()) {
        spdlog::get("MLSystem")->log(spdlog::level::warn, "Failed to open translations file({})", file);
        return "If you see this text, the getReplic call was incorrect(file stream open failed)";
    }
    nlohmann::json j; jsonFile >> j;
    if (j.contains(section)) {
        if (j[section].contains(replic)) {
            return j[section][replic].get<std::string>();
        } else {
            spdlog::get("MLSystem")->log(spdlog::level::warn, "The {} replic was not found in section {} in file {}", replic, section, file);
            return "If you see this text, the getReplic call was incorrect(replic was not found)";
        }
    } else {
        spdlog::get("MLSystem")->log(spdlog::level::warn, "The {} section was not found in file {}", section, file);
        return "If you see this text, the getReplic call was incorrect(section was not found)";
    }
}
