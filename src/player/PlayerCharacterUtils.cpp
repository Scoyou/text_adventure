#include "player/PlayerCharacterUtils.h"
#include <iostream>

PlayerCharacter createCharacter()
{
    PlayerCharacter pc;
    std::string name;
    std::string race;
    std::string description;

    std::cout << "Character name: ";
    std::cin >> name;
    std::cout << "Character race: ";
    std::cin >> race;

    // Convert to lowercase for easier comparison
    std::transform(race.begin(), race.end(), race.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });

    if (race == "orc")
    {
        pc.setRace(PlayableRace::Orc);
    }
    else if (race == "human")
    {
        pc.setRace(PlayableRace::Human);
    }
    else if (race == "elf")
    {
        pc.setRace(PlayableRace::Elf);
    }
    else
    {
        pc.setRace(PlayableRace::Human); // fallback
    }

    std::cout << "A brief description of your character: ";
    std::cin >> description;

    pc.setName(name);
    pc.setDescription(description);

    return pc;
}

int makeChoice()
{
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}
