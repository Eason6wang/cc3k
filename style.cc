#include "style.h"
#include <vector>
#include <string>

const std::vector<std::string> name {
    "Shade",
    "Drow",
    "Vampire",
    "Troll",
    "Goblin",
    "H",
    "W",
    "L",
    "E",
    "O",
    "D",
    "M",
    "Small Hoard",
    "Normal Hoard",
    "Dragon Hoard",
    "Merchant Hoard",
    "RH",
    "BA",
    "BD",
    "PH",
    "WA",
    "WD",
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
