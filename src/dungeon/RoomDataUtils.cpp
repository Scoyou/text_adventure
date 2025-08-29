#include "../../include/dungeon/RoomDataUtils.h"
#include <regex>

std::string fillTemplate(
    std::string text,
    const std::unordered_map<std::string, std::string>& values
) {
    for (const auto& [key, value] : values) {
        text = std::regex_replace(text, std::regex("\\{" + key + "\\}"), value);
    }
    return text;
}