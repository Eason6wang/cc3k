#include "normal_hoard.h"
#include "type.h"
#include "shade.h"

bool Normal_Hoard::be_visit (Shade &shade, Type type) {
	if (type == MOVE) {
		shade.getPlayerInfo().gold += getGold();
		return true;
	}
	if (type == ATTACK) {
		return false;
	}
}

Normal_Hoard::Normal_Hoard (int row, int col)
	:Treasure{row, col, NORMAL_HOARD, 2} {}
