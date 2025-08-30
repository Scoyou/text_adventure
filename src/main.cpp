#include <iostream>
#include "player/PlayerCharacterUtils.h"
#include "dungeon/DungeonUtils.h"

int clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

int main()
{
    // Create player and dungeon once
    PlayerCharacter player = createCharacter();
    Dungeon dungeon = createDungeon();
    clearBuffer();
    player.getStats();

    const int rows = 3;
    const int columns = 3;

    std::vector<std::vector<int>> room_ids(rows, std::vector<int>(columns));

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            Room room = createRoom();
            int id = r * columns + c + 1;
            room.id = id;
            room_ids[r][c] = id;
            dungeon.addRoom(room);
        }
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            int current = room_ids[r][c];

            if (r > 0)
            {
                // Connect north/south
                dungeon.connectRooms(current, "N", room_ids[r - 1][c], "S");
            }
            if (c > 0)
            {
                // Connect west/east
                dungeon.connectRooms(current, "W", room_ids[r][c - 1], "E");
            }
        }
    }

    dungeon.setStartingRoom(room_ids[0][0]);              // Top left room in grid
    dungeon.setExitRoom(room_ids[rows - 1][columns - 1]); // bottom right room

    Room &current_room = dungeon.getStartingRoom();

    while (current_room.id != dungeon.getExitRoom().id)
    {
        std::cout << "\nYou are in room " << current_room.id << std::endl;
        std::cout << current_room.description << std::endl;
        std::cout << "Monster: " << current_room.has_monster
                  << ", Treasure: " << current_room.has_treasure
                  << ", Trap: " << current_room.has_trap << std::endl;

        roomActions(current_room);

        roomNavigation(current_room, dungeon);
    }

    std::cout << "Congratulations! You reached the exit room!" << std::endl;
    return 0;
}
