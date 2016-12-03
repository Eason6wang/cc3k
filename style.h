#ifndef __STYLE__
#define __STYLE__
#include <vector>
#include <string>


enum Style {
    SHADE,
    DROW,
    VAMPIRE,
    TROLL,
    GOBLIN,
    HUMAN,
    DWARF,
    HALFLING,
    ELF,
    ORC,
    DRAGON,
    MERCHANT,
    SMALL_HOARD,
    NORMAL_HOARD,
    DRAGON_HOARD,
    MERCHANT_HOARD,
    RESTORE_HEALTH,
    BOOST_ATK,
    BOOST_DEF,
    POISON_HEALTH,
    WOUND_ATK,
    WOUND_DEF,
    SPACE,
    VERTICAL_WALL,
    HORIZONTAL_WALL,
    DOOR,
    TILE,
    PASSAGE,
    STAIR
};

std::string getString (Style style);

#endif
