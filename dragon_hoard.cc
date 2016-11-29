#include "dragon_hoard.h"
#include "type.h"
#include "shade.h"

bool Dragon__Hoard::be_visit (Shade &shade, Type type) {
	if (type == MOVE) {
		shade.getPlayerInfo().gold += getGold();
		return true;
	}
	if (type == ATTACK) {
		return false;
	}
}

Dragon__Hoard::Dragon__Hoard (int row, int col)
	:Treasure{row, col, DRAGON_HOARD, 6} {}

