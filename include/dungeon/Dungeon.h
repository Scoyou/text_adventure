#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>

struct Room {
    int id;
    std::string description;
    std::vector<int> connected_rooms;
    bool has_monster;
    bool has_treasure;
    bool has_trap;
    
    Room();
};

class Dungeon
{
    private:
        std::unordered_map<int, Room> rooms;
        int starting_room;
        int exit_room;
        
    public:
        Dungeon();

        void setStartingRoom(int id);
        void setExitRoom(int id);
        void addRoom(const Room& room);
        void connectRooms(int roomA, int roomB);

        Room& getRoom(int id);
        Room& getStartingRoom();
        Room& getExitRoom();
};

#endif
