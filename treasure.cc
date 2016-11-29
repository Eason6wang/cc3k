#include "treasure.h"
#include "object.h"

Treasure::Treasure (int row, int col, Style style, int gold) 
		:Item{row, col, style}, gold{gold} {}

int Treasure::getGold () { return gold; }

