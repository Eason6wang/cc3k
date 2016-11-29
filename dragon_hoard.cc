#include "dragon_hoard.h"

Dragon_Hoard::Dragon_Hoard (int posx, int posy, Style style, int gold)
		:Treasure{posx, posy, style, gold} {}

bool Dragon_Hoard::be_visit (Player &player, Type type) {
	if (type == MOVE) return true;
	else return false;
}
