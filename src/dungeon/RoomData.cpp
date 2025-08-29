#include "../../include/dungeon/RoomData.h"
#include <string>
#include <vector>
#include <regex>

namespace RoomData
{
    const std::vector<std::string> sounds = {
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
    const std::vector<std::string> light_levels = {
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
    const std::vector<std::string> ambient_effects = {
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
    const std::vector<std::string> templates = {
        "You enter a {adjective} {room_type}. It's {light_level}, and the air smells of {scent}. You hear {sound}. {ambient_effect} fills the space. In the corner, you see {feature}.",
        "This {room_type} is {adjective}. {feature} lies ahead. It's {light_level}, the scent of {scent} hangs thick, and {sound} can be heard. Around you, {ambient_effect}.",
        "You step into a {adjective} {room_type}, where {feature} catches your eye. The air reeks of {scent}, it's {light_level}, and {sound} fills your ears. {ambient_effect} completes the scene.",
        "A {scent} stench clings to the air in this {adjective} {room_type}. It's {light_level}. There, ahead, is {feature}. You hear {sound}, and {ambient_effect} surrounds you.",
        "As you cross the threshold into the {adjective} {room_type}, you're met with the strong smell of {scent}. It's {light_level}, {feature} is visible, and {sound} echoes softly. {ambient_effect} lingers.",
        "This {room_type} feels especially {adjective}. {feature} stands out. It's {light_level}, and the smell of {scent} mixes with {sound}. {ambient_effect} makes the room feel alive."};
    const std::vector<std::string> scents = {
        "rot and decay", "damp earth and mold", "stale blood and iron", "burnt oil and smoke",
        "sulfur and ash", "wet stone", "mildew and fungus", "ancient dust", "animal musk", "smoldering wood"};
    const std::vector<std::string> features = {
        "a chest", "a door", "a trap", "a monster", "a treasure chest",
        "an altar", "a skeleton", "a broken statue", "a glowing rune", "a hidden lever"};
    const std::vector<std::string> room_types = {
        "cave", "cavern", "dungeon", "hall", "room",
        "crypt", "cellar", "chamber", "passage", "lair"};
    const std::vector<std::string> adjectives = {
        "dark", "dangerous", "dusty", "empty", "foggy",
        "cramped", "echoing", "twisting", "flooded", "gloomy"};
}
