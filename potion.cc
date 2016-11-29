#include "potion.h"

using namespace std;

Potion::Potion (int posx, int posy, Style style, shared_ptr<Potion> potion);
	:Item{posx, posy, style},potion{potion} {}

bool Potion::be_visit (Player &player, Type type) {
	if (type == MOVE) {
	player.potion = shared_ptr<Potion> (0, 0,
		   	potion->getinfo().style, potion);
	return true;
	}
	if (type == ATTACK) throw attack_exception{};
}
