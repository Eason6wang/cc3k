#include "small_hoard.h"
#include "type.h"
#include "shade.h"

bool Small_Hoard::be_visit (Shade &shade, Type type) {
	if (type == MOVE) {
		shade.getPlayerInfo().gold += getGold();
		//throw to let floor change the floor.
		return true;
	}
	if (type == ATTACK) {
		return false;
	}
}

Small_Hoard::Small_Hoard (int row, int col)
	:Treasure{row, col, SMALL_HOARD, 1} {}
