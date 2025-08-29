#ifndef ROOM_DATA_UTILS
#define ROOM_DATA_UTILS
#include <iostream>
#include <random>
#include "RoomData.h"

// Returns a random element from the given vector using a uniform distribution.
template <typename T>
const T& randomChoice(const std::vector<T>& list) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, list.size() - 1);
    return list[dist(gen)];
}


std::string fillTemplate(
    std::string text,
    const std::unordered_map<std::string, std::string>& values
);

#endif
