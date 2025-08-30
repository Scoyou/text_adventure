#include "monster/MonsterUtils.h"

Monster createMonster(std::string name, std::string description, std::string race, int health, int attack, int defense) {
    Monster newMonster(name, description,race, health, attack, defense);
    return newMonster;
}
