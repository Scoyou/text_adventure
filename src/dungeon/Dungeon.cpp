#include "../../include/dungeon/Dungeon.h"
#include <iostream>

void Dungeon::setStartingRoom(int id) { this->starting_room = id; }
void Dungeon::setExitRoom(int id) { this->exit_room = id; }
void Dungeon::addRoom(const Room& room) { }