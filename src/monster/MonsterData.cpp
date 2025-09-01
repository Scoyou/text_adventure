#include "monster/MonsterData.h"
#include <map>
#include <string>
#include <vector>

namespace MonsterData
{
    const std::map<std::string, std::string> races = {
        {"Goblin", "Small, green-skinned creatures known for mischief and cunning."},
        {"Troll", "Large and strong, but often slow-witted. Known to regenerate."},
        {"Kobold", "Small, reptilian humanoids often found in caves and mines."},
        {"Orc", "Brutish warriors with a fierce sense of tribe and conquest."},
        {"Vampire", "Undead beings who feed on blood and shun sunlight."}};

    const std::vector<std::string> intros = {
        "stares at you menacingly",
        "lets out a terrifying roar",
        "launches forward to attack",
        "bares its sharp fangs",
        "swipes with its claws",
        "breathes fire in your direction",
        "stomps the ground fiercely",
        "snarls and growls",
        "circles you like a predator",
        "lashes out with its tail",
        "prepares to pounce",
        "charges with reckless fury",
        "howls into the night",
        "raises its weapon high",
        "emits a bone-chilling screech",
        "slams the ground, shaking the earth",
        "glows with a dark aura",
        "fixes its glowing eyes on you",
        "creeps closer, step by step"};

    std::string getDescription(const std::string &race)
    {
        auto it = races.find(race);
        if (it != races.end())
        {
            return it->second;
        }
        return "Unknown race.";
    }

    std::string getRandomIntro()
    {
        if (intros.empty())
            return "";
        return intros[rand() % intros.size()];
    }
}
