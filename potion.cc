#include "potion.h"
#include <memory>

using namespace std;

Potion::Potion (int posx, int posy, Style style, shared_ptr<Potion> potion);
	:Item{posx, posy, style},potion{potion} {}

bool Treasure::be_visit (Shade &player, Type type) {
		if (type == PICKUP) {
			getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,getPlayerInfo().potion);
			return true;
		} else return false;
}	
bool Treasure::be_visit (Drow &player, Type type) {
		if (type == PICKUP) {
			getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,getPlayerInfo().potion);
			return true;
		} else return false;
}	
bool Treasure::be_visit (Troll &player, Type type) {
		if (type == PICKUP) {
			getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,getPlayerInfo().potion);
			return true;
		} else return false;
}	
bool Treasure::be_visit (Vampire&player, Type type) {
		if (type == PICKUP) {
			getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,getPlayerInfo().potion);
			return true;
		} else return false;
}	
bool Treasure::be_visit (Goblin &player, Type type) {
		if (type == PICKUP) {
			getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,getPlayerInfo().potion);
			return true;
		} else return false;
}	
/*bool Potion::be_visit (Player &player, Type type) {
	if (type == MOVE) {
	player.potion = shared_ptr<Potion> (0, 0,
		   	potion->getinfo().style, potion);
	return true;
	}
	if (type == ATTACK) throw attack_exception{};
}*/
