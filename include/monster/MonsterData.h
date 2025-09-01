#ifndef MONSTERDATA_H
#define MONSTERDATA_H

#include <string>
#include <map>
#include <vector>

namespace MonsterData
{
    extern const std::map<std::string, std::string> races;
    extern const std::vector<std::string> intros;

    std::string getDescription(const std::string& race);
    std::string getRandomIntro();
}

#endif
