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
#include "buff.h"
#include "style.h"
#include "type.h"

using namespace std;

Potion::Potion (int posx, int posy, Style style)
	:Item{posx, posy, style} {}


Info &Potion::modify(){
    if(potion){	
      info.hp = potion->modify().hp;
    }
    return info;
}

shared_ptr<Potion> &Potion::getPotion(){
    return potion;
}

bool Potion::be_visit (Shade &player, Type type) {
/*		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
		*/
	return be_visit_by(*this, player, type, getPos().style);
}	

bool Potion::be_visit (Drow &player, Type type) {
	/*	if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
		*/
	return be_visit_by(*this, player, type, getPos().style);

}	

bool Potion::be_visit (Troll &player, Type type) {
/*		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
		*/
return be_visit_by(*this, player, type, getPos().style);

}	

bool Potion::be_visit (Vampire&player, Type type) {
/*		if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
		*/
return be_visit_by(*this, player, type, getPos().style);

}	
bool Potion::be_visit (Goblin &player, Type type) {
		/*if (type == PICKUP) {
			player.getPlayerInfo().potion = 
				std::make_shared<Potion> (0,0,getPos().style,player.getPlayerInfo().potion);
			throw VisitExcept {"pickup_potion", 0};
		} else return false;
*/
return be_visit_by(*this, player, type, getPos().style);

}
