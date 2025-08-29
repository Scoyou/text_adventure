#include "../../include/dungeon/DungeonUtils.h"
#include "../../include/dungeon/RoomDataUtils.h"
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

    room.has_monster = (feature == "a monster");
    room.has_treasure = (feature == "a chest" || feature == "a treasure chest");
    room.has_trap = (feature == "a trap") ||
                    ((feature == "a chest" || feature == "a treasure chest" || feature == "a hidden lever") && rand() % 2);

    return room;
}
