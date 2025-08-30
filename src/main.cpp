#include <iostream>
#include "player/PlayerCharacterUtils.h"
#include "dungeon/DungeonUtils.h"
#include "monster/MonsterUtils.h"

int clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

void roomActions(Room &current_room)
{
    if (current_room.has_monster)
    {
        std::cout << "You see a monster!" << std::endl;
        Monster monster = createMonster("Goblin", "A small goblin", "Goblin", 10, 5, 2);

        std::cout << "Name: " << monster.getName() << std::endl;
        std::cout << "Description: " << monster.getDescription() << std::endl;
        std::cout << "Race: " << monster.getRace() << std::endl;
        std::cout << "Health: " << monster.getHealth() << std::endl;
        std::cout << "Attack: " << monster.getAttack() << std::endl;
        std::cout << "Defense: " << monster.getDefense() << std::endl;
    }
    else if (current_room.has_treasure)
    {
        std::cout << "You see a treasure!" << std::endl;
    }
    else if (current_room.has_trap)
    {
        std::cout << "You see a trap!" << std::endl;
    }
}

void roomNavigation(Room &current_room, Dungeon &dungeon)
{
    std::cout << "You can go: ";
    for (const auto &kv : current_room.connected_rooms)
    {
        std::cout << kv.first << ", ";
    }
    std::cout << std::endl;

    std::cout << "Enter direction (N, S, E, W): ";
    std::string input;
    std::cin >> input;

    // Transform input to uppercase
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);

    if (current_room.connected_rooms.find(input) != current_room.connected_rooms.end())
    {
        int next_room_id = current_room.connected_rooms[input];
        current_room = dungeon.getRoom(next_room_id); // move to that room
    }
    else
    {
        std::cout << "You can't go that way!" << std::endl;
    }
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
