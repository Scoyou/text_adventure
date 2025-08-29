#include "../../include/dungeon/Dungeon.h"

Dungeon::Dungeon() {}
Room::Room() : id(++next_id), description(""), connected_rooms({}), has_monster(false), has_treasure(false) {}

void Dungeon::setStartingRoom(int id) { this->starting_room = id; }
void Dungeon::setExitRoom(int id) { this->exit_room = id; }
void Dungeon::addRoom(const Room& room) { this->rooms[room.id] = room; }
void Dungeon::connectRooms(int roomA, int roomB) { this->rooms[roomA].connected_rooms.push_back(roomB); }
Room& Dungeon::getRoom(int id) { return this->rooms[id]; }
Room& Dungeon::getStartingRoom() { return this->rooms[this->starting_room]; }
Room& Dungeon::getExitRoom() { return this->rooms[this->exit_room]; }
int Room::next_id = 0;
