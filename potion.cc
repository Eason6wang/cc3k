#include "potion.h"
#include <memory>
#include "pos.h"
#include "player.h"
#include "playerinfo.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "visitexcept.h"

using namespace std;

Potion::Potion (int posx, int posy, Style style, shared_ptr<Potion> potion)
	:Item{posx, posy, style},potion{potion} {}

bool Potion::be_visit (Shade &player, Type type) {
		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
}	
bool Potion::be_visit (Drow &player, Type type) {
		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
}	
bool Potion::be_visit (Troll &player, Type type) {
		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
}	
bool Potion::be_visit (Vampire&player, Type type) {
		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
}	
bool Potion::be_visit (Goblin &player, Type type) {
		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;

}
Info Potion::modify () {
	return Info {0,0,0};
}
/*bool Potion::be_visit (Player &player, Type type) {
	if (type == MOVE) {
	player.potion = shared_ptr<Potion> (0, 0,
		   	potion->getinfo().style, potion);
	return true;
	}
	if (type == ATTACK) throw attack_exception{};
}*/
