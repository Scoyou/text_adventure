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
    std::string sounds[10] = {
        "dripping water echoing in the dark",
        "distant footsteps",
        "a low growl rumbling nearby",
        "the clinking of chains",
        "faint whispers from unseen mouths",
        "scratching behind the walls",
        "the fluttering of wings overhead",
        "a sudden crash in the distance",
        "a soft chanting in an unknown tongue",
        "the crackle of fire"};
    std::string light_levels[10] = {
        "pitch black",
        "dimly lit by a single torch",
        "glowing faintly with magical light",
        "bathed in eerie green light",
        "flickering with unstable firelight",
        "lit by cracks in the ceiling",
        "swallowed in heavy shadows",
        "lit with a pulsing red glow",
        "bright enough to see, but with no visible source",
        "illuminated by bioluminescent fungi"};
    std::string ambient_effects[10] = {
        "a thick fog clings to the ground",
        "dust motes float through the air",
        "cobwebs hang from the ceiling",
        "arcane symbols glow faintly on the walls",
        "steam rises from cracks in the floor",
        "moss covers the stones",
        "a cold draft blows from deeper within",
        "puddles reflect distorted shapes",
        "crystals jut out from the walls",
        "shadows seem to move on their own"};
    std::string templates[6] = {
        "You enter a {adjective} {room_type}. It's {light_level}, and the air smells of {scent}. You hear {sound}. {ambient_effect} fills the space. In the corner, you see {feature}.",
        "This {room_type} is {adjective}. {feature} lies ahead. It's {light_level}, the scent of {scent} hangs thick, and {sound} can be heard. Around you, {ambient_effect}.",
        "You step into a {adjective} {room_type}, where {feature} catches your eye. The air reeks of {scent}, it's {light_level}, and {sound} fills your ears. {ambient_effect} completes the scene.",
        "A {scent} stench clings to the air in this {adjective} {room_type}. It's {light_level}. There, ahead, is {feature}. You hear {sound}, and {ambient_effect} surrounds you.",
        "As you cross the threshold into the {adjective} {room_type}, you're met with the strong smell of {scent}. It's {light_level}, {feature} is visible, and {sound} echoes softly. {ambient_effect} lingers.",
        "This {room_type} feels especially {adjective}. {feature} stands out. It's {light_level}, and the smell of {scent} mixes with {sound}. {ambient_effect} makes the room feel alive."};
    std::string scents[10] = {
        "rot and decay", "damp earth and mold", "stale blood and iron", "burnt oil and smoke",
        "sulfur and ash", "wet stone", "mildew and fungus", "ancient dust", "animal musk", "smoldering wood"};
    std::string features[10] = {
        "a chest", "a door", "a trap", "a monster", "a treasure chest",
        "an altar", "a skeleton", "a broken statue", "a glowing rune", "a hidden lever"};
    std::string room_types[10] = {
        "cave", "cavern", "dungeon", "hall", "room",
        "crypt", "cellar", "chamber", "passage", "lair"};
    std::string adjectives[10] = {
        "dark", "dangerous", "dusty", "empty", "foggy",
        "cramped", "echoing", "twisting", "flooded", "gloomy"};

    srand(static_cast<unsigned int>(time(0)));

    std::string room_adjective{adjectives[rand() % 10]};
    std::string room_type{room_types[rand() % 10]};
    std::string room_feature{features[rand() % 10]};
    std::string room_scent{scents[rand() % 10]};
    std::string room_sound{sounds[rand() % 10]};
    std::string room_light_level{light_levels[rand() % 10]};
    std::string room_ambient_effect{ambient_effects[rand() % 10]};

    std::string room_template = templates[rand() % 3];
    room_template = std::regex_replace(room_template, std::regex("\\{adjective\\}"), room_adjective);
    room_template = std::regex_replace(room_template, std::regex("\\{room_type\\}"), room_type);
    room_template = std::regex_replace(room_template, std::regex("\\{feature\\}"), room_feature);
    room_template = std::regex_replace(room_template, std::regex("\\{scent\\}"), room_scent);
    room_template = std::regex_replace(room_template, std::regex("\\{sounds\\}"), room_sound);
    room_template = std::regex_replace(room_template, std::regex("\\{light_level\\}"), room_light_level);
    room_template = std::regex_replace(room_template, std::regex("\\{ambient_effects\\}"), room_ambient_effect);

    room.description = room_template;

    if (room_feature == "a monster")
    {
        room.has_monster = 1;
    }

    if (room_feature == "a chest" || room_feature == "a treasure chest")
    {
        room.has_treasure = 1;
    }

    if (room_feature == "a trap")
    {
        room.has_trap = 1;
    }

    if (room_feature == "a chest" || room_feature == "a treasure chest" || room_feature == "a hidden lever")
    {
        room.has_trap = rand() % 2;
    }

    return room;
}
