#include "dungeon/Dungeon.h"

Dungeon::Dungeon() {}
Room::Room() : id(0), description(""), connected_rooms({}), has_monster(false), has_treasure(false) {}

void Dungeon::setStartingRoom(int id) { this->starting_room = id; }
void Dungeon::setExitRoom(int id) { this->exit_room = id; }
void Dungeon::addRoom(const Room& room) { this->rooms[room.id] = room; }
void Dungeon::connectRooms(int roomA, const std::string& dirA, int roomB, const std::string& dirB) {
    rooms[roomA].connected_rooms[dirA] = roomB;
    rooms[roomB].connected_rooms[dirB] = roomA;
}

Room& Dungeon::getRoom(int id) { return this->rooms[id]; }
Room& Dungeon::getStartingRoom() { return this->rooms[this->starting_room]; }
Room& Dungeon::getExitRoom() { return this->rooms[this->exit_room]; }
