#include "monster/Monster.h"

// Constructor
Monster::Monster(const std::string& name,
                 const std::string& description,
                 const std::string& race,
                 int health,
                 int attack,
                 int defense)
    : name(name),
      description(description),
      race(race),
      health(health),
      attack(attack),
      defense(defense)
{}

// Getters
const std::string& Monster::getName() const { return name; }
const std::string& Monster::getDescription() const { return description; }
const std::string& Monster::getRace() const { return race; }
int Monster::getHealth() const { return health; }
int Monster::getAttack() const { return attack; }
int Monster::getDefense() const { return defense; }

// Setters
void Monster::setName(const std::string& newName) { name = newName; }
void Monster::setDescription(const std::string& newDescription) { description = newDescription; }
void Monster::setRace(const std::string& newRace) { race = newRace; }
void Monster::setHealth(int newHealth) { health = newHealth; }
void Monster::setAttack(int newAttack) { attack = newAttack; }
void Monster::setDefense(int newDefense) { defense = newDefense; }
