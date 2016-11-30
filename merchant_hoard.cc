#include "merchant_hoard.h"
#include "type.h"
#include "shade.h"

bool Merchant_Hoard::be_visit (Shade &shade, Type type) {
	if (type == MOVE) {
		shade.getPlayerInfo().gold += getGold();
		return true;
	}
	if (type == ATTACK) {
		return false;
	}
}

Merchant_Hoard::Merchant_Hoard (int row, int col)
	:Treasure{row, col, MERCHANT_HOARD, 4} {}