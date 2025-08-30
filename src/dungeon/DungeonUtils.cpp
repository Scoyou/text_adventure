#include "dungeon/DungeonUtils.h"
#include "dungeon/RoomDataUtils.h"
#include <cstdlib>
#include <ctime>
#include "monster/MonsterUtils.h"

Dungeon createDungeon()
{
    Dungeon dungeon;
    return dungeon;
}

Room createRoom()
{
    Room room;

    std::string adjective{randomChoice(RoomData::adjectives)};
    std::string type{randomChoice(RoomData::room_types)};
    std::string feature{randomChoice(RoomData::features)};
    std::string scent{randomChoice(RoomData::scents)};
    std::string sound{randomChoice(RoomData::sounds)};
    std::string light_level{randomChoice(RoomData::light_levels)};
    std::string ambient_effect{randomChoice(RoomData::ambient_effects)};

    std::string tmpl = randomChoice(RoomData::templates);
    room.description = fillTemplate(tmpl, {{"adjective", adjective},
                                           {"room_type", type},
                                           {"feature", feature},
                                           {"scent", scent},
                                           {"sound", sound},
                                           {"light_level", light_level},
                                           {"ambient_effect", ambient_effect}});

    room.has_monster = rand() % 2;
    room.has_treasure = rand() % 2;
    room.has_trap = (!room.has_monster && rand() % 2); // don't trap rooms with a monster

    return room;
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
