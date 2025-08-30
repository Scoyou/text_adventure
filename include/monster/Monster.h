#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster
{
    private:
        std::string name;
        std::string description;
        std::string race;
        int health;
        int attack;
        int defense;

    public:
        Monster(std::string name, std::string description, std::string race, int health, int attack, int defense);

        std::string getName();
        std::string getDescription();
        int getHealth();
        int getAttack();
        int getDefense();
        std::string getRace();
};
#endif
