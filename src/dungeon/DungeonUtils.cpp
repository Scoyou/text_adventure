#include "../../include/dungeon/DungeonUtils.h"
#include <iostream>

Dungeon createDungeon() {
    Dungeon dungeon;
    return dungeon;
}

Room createRoom() {
    std::string adjectives[5] = {"dark", "dangerous", "dusty", "empty", "foggy"};
    std::string room_types[5] = {"cave", "cavern", "dungeon", "hall", "room"};
    std::string features[5] = {"a chest", "a door", "a trap", "a monster", "a treasure chest"};
    std::string scents[5] = {"rotting flesh", "decaying bones", "rotting flesh", "decaying bones", "rotting flesh"};

    std::string templates[3] = {
        "You enter a {adjective} {room_type}. The air smells of {scent}. In the corner, you see {feature}.",
        "This {room_type} is {adjective}. {feature} lies ahead, and the smell of {scent} lingers in the air.",
        "You step into a {adjective} {room_type}, where {feature} catches your eye. The air reeks of {scent}."
    };

    Room room;
    return room;
}

