#include <iostream>
#include "../include/player/PlayerCharacterUtils.h"
#include "../include/dungeon/DungeonUtils.h"

int clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

int main()
{
    while(true)
    {
        PlayerCharacter player;
        player = createCharacter();
        clearBuffer();

        std::cout << "Character name: " << player.getName() << std::endl;
        std::cout << "Character race: " << player.getRace() << std::endl;
        std::cout << "Character description: " << player.getDescription() << std::endl;
        std::cout << "Character level: " << player.getLevel() << std::endl;
        std::cout << "Character health: " << player.getHealth() << std::endl;
        std::cout << "Character experience points: " << player.getExperiencePoints() << std::endl;

        Room room;
        room = createRoom();
        clearBuffer();
        std::cout << room.description << std::endl;

    }
    return 0;
}
