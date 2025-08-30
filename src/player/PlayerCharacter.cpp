#include "player/PlayerCharacter.h"
#include <iostream>

PlayerCharacter::PlayerCharacter(
    std::string name,
    PlayableRace race,
    std::string description,
    int level,
    int health,
    int experience_points,
    int attack,
    int defence,
    int dexterity)
    : name(""), race(PlayableRace::Human), description(""), level(1), health(100), experience_points(0), attack(0), defence(0), dexterity(0) {}

std::string PlayerCharacter::getName() { return name; }
PlayableRace PlayerCharacter::getRace() { return race; }
std::string PlayerCharacter::getDescription() { return description; }
int PlayerCharacter::getLevel() { return level; }
int PlayerCharacter::getHealth() { return health; }
int PlayerCharacter::getExperiencePoints() { return experience_points; }
int PlayerCharacter::getAttack() { return attack; }
int PlayerCharacter::getDefence() { return defence; }
int PlayerCharacter::getDexterity() { return dexterity; }

void PlayerCharacter::setName(std::string name) { this->name = name; }
void PlayerCharacter::setRace(PlayableRace race) { this->race = race; }
void PlayerCharacter::setDescription(std::string description) { this->description = description; }
void PlayerCharacter::setLevel(int level) { this->level = level; }
void PlayerCharacter::setHealth(int health_points) { this->health = health_points; }
void PlayerCharacter::setExperiencePoints(int experience_points) { this->experience_points = experience_points; }
void PlayerCharacter::setAttack(int attack) { this->attack = attack; }
void PlayerCharacter::setDefence(int defence) { this->defence = defence; }
void PlayerCharacter::setDexterity(int dexterity) { this->dexterity = dexterity; }

bool PlayerCharacter::isAlive()
{
    return this->health > 0;
}

void PlayerCharacter::getStats()
{
    std::string stringified_race;

    switch(this->race)
    {
        case PlayableRace::Orc:
            stringified_race = "Ork";
            break;
        case PlayableRace::Human:
            stringified_race = "Human";
            break;
        case PlayableRace::Elf:
            stringified_race = "Elf";
            break;
        default:
            // fallback to basic human
            stringified_race = "Human";
            break;
    }

    std::cout << "Character Name: "<< this->name << "\n";
    std::cout << "Character Race: " << stringified_race << "\n";
    std::cout << "Character Description: " << this->description << "\n";
    std::cout << "Character Level: " << this->level << "\n";
    std::cout << "Character Health: " << this->health << "\n";
    std::cout << "Character Experience: " << this->experience_points << "\n";
}
