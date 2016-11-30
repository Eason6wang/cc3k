#include "style.h"
#include <vector>
#include <string>

const std::vector<std::string> name {
    "Shade",
    "Drow",
    "Vampire",
    "Troll",
    "Goblin",
    "Human",
    "Dwarf",
    "Halfling",
    "Elf",
    "Orc",
    "Dragon",
    "Merchant",
    "Small Hoard",
    "Normal Hoard",
    "Dragon Hoard",
    "Merchant Hoard",
    "Restore Health",
    "Boost Attack",
    "Boost Defense",
    "Poison Health",
    "Wound Attack",
    "Wound Defense",
    "Space",
    "Vertical Wall",
    "Horizontal Wall",
    "Door",
    "Tile",
    "Passage",
    "Stair"
};

std::string getString (Style style) {
	return name.at(style);
}
