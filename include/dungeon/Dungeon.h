#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>

struct Room {
    int id;
    std::string description;
    std::vector<int> connected_rooms;
    bool has_monster;
    bool has_treasure;
};

class Dungeon
{
    private:
        std::unordered_map<int, Room> rooms;
        int starting_room;
        int exit_room;
        
    public:

};

#endif