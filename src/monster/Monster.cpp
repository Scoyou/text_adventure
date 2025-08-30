#include "monster/Monster.h"

Monster::Monster(std::string name, std::string description, std::string race, int health, int attack, int defense) {};

std::string Monster::getName() { return name; }
std::string Monster::getDescription() { return description; }
int Monster::getHealth() { return health; }
int Monster::getAttack() { return attack; }
int Monster::getDefense() { return defense; }
std::string Monster::getRace() { return race; }
