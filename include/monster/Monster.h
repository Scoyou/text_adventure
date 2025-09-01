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
    Monster(const std::string& name = "",
            const std::string& description = "",
            const std::string& race = "",
            int health = 0,
            int attack = 0,
            int defense = 0);

    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::string& getRace() const;
    int getHealth() const;
    int getAttack() const;
    int getDefense() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setRace(const std::string& race);
    void setHealth(int health);
    void setAttack(int attack);
    void setDefense(int defense);
};

#endif // MONSTER_H
