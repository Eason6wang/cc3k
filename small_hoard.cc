#include "small_hoard.h"
#include "object.h"
#include "player.h"
#include "attack_exception.h"

Small_Hoard::bool visit (Object &object, Type type) {
	object.be_visit (*this, type);
}

bool Small_Hoard::be_visit (Player &player, Type type) {
	if (type == MOVE) {
		player.getInfo().gold += getGold();
		return true;
	}
	if (type == ATTACK) {
		throw attack_exception {getPos().style};
	}
}

Small_Hoard::Small_Hoard (int posx, int posy, Style style, int gold)
	:Treasure{posx, posy, style, gold} {}
