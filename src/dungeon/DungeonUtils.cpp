#include "../../include/dungeon/DungeonUtils.h"
#include <iostream>
#include <regex>
#include <cstdlib>
#include <ctime>

Dungeon createDungeon()
{
    Dungeon dungeon;
    return dungeon;
}

Room createRoom()
{
    Room room;

    std::string adjectives[5] = {"dark", "dangerous", "dusty", "empty", "foggy"};
    std::string room_types[5] = {"cave", "cavern", "dungeon", "hall", "room"};
    std::string features[5] = {"a chest", "a door", "a trap", "a monster", "a treasure chest"};
    std::string scents[5] = {"rotting flesh", "decaying bones", "rotting flesh", "decaying bones", "rotting flesh"};

    std::string templates[3] = {
        "You enter a {adjective} {room_type}. The air smells of {scent}. In the corner, you see {feature}.",
        "This {room_type} is {adjective}. {feature} lies ahead, and the smell of {scent} lingers in the air.",
        "You step into a {adjective} {room_type}, where {feature} catches your eye. The air reeks of {scent}."};

    srand(static_cast<unsigned int>(time(0)));

    std::string room_template = templates[rand() % 3];
    room_template = std::regex_replace(room_template, std::regex("\\{adjective\\}"), adjectives[rand() % 5]);
    room_template = std::regex_replace(room_template, std::regex("\\{room_type\\}"), room_types[rand() % 5]);
    room_template = std::regex_replace(room_template, std::regex("\\{feature\\}"), features[rand() % 5]);
    room_template = std::regex_replace(room_template, std::regex("\\{scent\\}"), scents[rand() % 5]);

    room.description = room_template;
    room.has_monster = rand() % 2;
    room.has_treasure = rand() % 2;

    return room;
}
