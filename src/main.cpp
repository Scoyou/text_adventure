#include <iostream>
#include "../include/player/PlayerCharacterUtils.h"
#include "../include/dungeon/DungeonUtils.h"

int clearBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

int main() {
    // Create player and dungeon once
    PlayerCharacter player = createCharacter();
    Dungeon dungeon = createDungeon();
    clearBuffer();
    player.getStats();

    // Create rooms
    std::vector<Room> rooms;
    for (int i = 0; i < 5; i++) {
        rooms.push_back(createRoom());
    }

    // Add rooms to dungeon
    for (Room &r : rooms) {
        dungeon.addRoom(r);
    }

    // Connect rooms linearly
    for (size_t i = 0; i < rooms.size() - 1; i++) {
        dungeon.connectRooms(rooms[i].id, rooms[i + 1].id);
    }

    dungeon.setStartingRoom(rooms.front().id);
    dungeon.setExitRoom(rooms.back().id);

    // Map directions to indices (0=N, 1=S, 2=E, 3=W)
    std::unordered_map<std::string, int> direction_map = {
        {"N", 0}, {"S", 1}, {"E", 2}, {"W", 3}
    };

    Room& current_room = dungeon.getStartingRoom();

    while (current_room.id != dungeon.getExitRoom().id) {
        std::cout << "\nYou are in room " << current_room.id << std::endl;
        std::cout << current_room.description << std::endl;
        std::cout << "Monster: " << current_room.has_monster
                  << ", Treasure: " << current_room.has_treasure
                  << ", Trap: " << current_room.has_trap << std::endl;

        std::cout << "Enter direction (N, S, E, W): ";
        std::string input;
        std::cin >> input;

        // Check if direction is valid
        if (direction_map.find(input) != direction_map.end()) {
            int dir_index = direction_map[input];

            // Check if the room has a connected room in that direction
            if (dir_index < current_room.connected_rooms.size()) {
                int next_room_id = current_room.connected_rooms[dir_index];
                current_room = dungeon.getRoom(next_room_id); // Move to next room
            } else {
                std::cout << "You can't go that way!" << std::endl;
            }
        } else {
            std::cout << "Invalid direction!" << std::endl;
        }
    }

    std::cout << "Congratulations! You reached the exit room!" << std::endl;
    return 0;
}
