#ifndef DUNGEON_UTILS_H
#define DUNGEON_UTILS_H

#include "Dungeon.h"

Dungeon createDungeon();
Room createRoom();
void roomActions(Room& current_room);
void roomNavigation(Room &current_room, Dungeon &dungeon);
#endif
