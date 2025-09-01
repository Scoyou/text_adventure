#include "monster/MonsterUtils.h"
#include "random/RandomUtils.h"
#include "monster/MonsterData.h"
#include <vector>
#include <cstdlib>

Monster createMonster()
{
    // Extract races (keys) from map into a vector
    std::vector<std::string> raceKeys;
    raceKeys.reserve(MonsterData::races.size());
    for (const auto& [race, _] : MonsterData::races) {
        raceKeys.push_back(race);
    }

    std::string race = randomChoice(raceKeys);

    std::string description = MonsterData::getDescription(race) 
                            + " It " + MonsterData::getRandomIntro() + ".";

    int health  = rand() % 100 + 1;
    int attack  = rand() % 10 + 1;
    int defense = rand() % 10 + 1;

    return Monster(
        race,
        description,
        race,
        health,
        attack,
        defense
    );
}
