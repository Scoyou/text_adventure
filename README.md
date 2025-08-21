# 🏰 Text Adventure

A simple **text-based adventure game** written in modern C++17.\
The player can create a character, explore dungeons, fight enemies, and
progress through an adventure world.

------------------------------------------------------------------------

## ✨ Features

-   Character creation (name, race, description)
-   Basic player stats (health, level, experience points)
-   Dungeon exploration system (rooms, enemies, treasures)
-   Turn-based combat
-   Modular project structure (`player/`, `dungeon/`, etc.)
-   Built with **CMake**

------------------------------------------------------------------------

## 📂 Project Structure

    text_adventure/
    │
    ├── include/               # Header files
    │   ├── player/            # Player-related headers
    │   │   └── PlayerCharacter.h
    │   └── dungeon/           # Dungeon-related headers
    │       └── Dungeon.h
    │
    ├── src/                   # Source files
    │   ├── main.cpp
    │   ├── player/
    │   │   └── PlayerCharacter.cpp
    │   └── dungeon/
    │       └── Dungeon.cpp
    │
    ├── build/                 # Build output (created after compiling)
    └── CMakeLists.txt         # Build configuration

------------------------------------------------------------------------

## ⚙️ Build Instructions

### Prerequisites

-   **C++17** or later\
-   [CMake](https://cmake.org/) (version 3.15+)\
-   A compiler such as:
    -   `g++` (Linux/macOS)
    -   `clang++` (macOS)
    -   MSVC (`cl.exe`) (Windows)

### Build Steps

``` bash
# Clone the project
git clone https://github.com/your-username/text_adventure.git
cd text_adventure

# Create a build directory
mkdir build
cd build

# Generate build files with CMake
cmake ..

# Compile
cmake --build .
```

### Run

``` bash
./text_adventure
```

------------------------------------------------------------------------

## 🎮 How to Play

1.  Launch the game.\
2.  Create your character (choose name, race, description).\
3.  Explore dungeons and make choices by typing commands.\
4.  Survive battles, collect treasure, and grow stronger!

------------------------------------------------------------------------

## 🔮 Future Plans

-   Inventory system (weapons, potions, loot)\
-   Smarter dungeon generation\
-   Story-driven branching quests\
-   Save/load game progress

------------------------------------------------------------------------

## 🤝 Contributing

Contributions, bug reports, and feature requests are welcome!\
Feel free to fork the repo and submit pull requests.

------------------------------------------------------------------------

## 📜 License

This project is licensed under the [MIT License](LICENSE).
