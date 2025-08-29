#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include <iostream>

enum PlayableRace {
    Orc,
    Elf,
    Human
};

class PlayerCharacter
{
    private:
        std::string name;
        PlayableRace race;
        std::string description;
        int level;
        int health;
        int experience_points;

    public:

        PlayerCharacter(
            std::string name="",
            PlayableRace race=PlayableRace::Human,
            std::string description="",
            int level=1,
            int health=100,
            int experience_points=0);

        std::string getName();
        PlayableRace getRace();
        std::string getDescription();
        int getLevel();
        float getHealth();
        float getExperiencePoints();

        void setName(std::string name);
        void setRace(PlayableRace race);
        void setDescription(std::string description);
        void setLevel(int level);
        void setHealth(int health_points);
        void setExperiencePoints(int experience_points);

        bool isAlive();
        void getStats();
};

#endif
