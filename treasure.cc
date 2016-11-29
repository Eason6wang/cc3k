#include "treasure.h"
#include "object.h"

Treasure::bool visit (Object &object, Type type){
	object.be_visit (*this, Type type);
}

Treasure::Treasure (int pos, int posy, Style style, int gold) 
		:Item{posx, posy, style}, gold{gold} {}

Treasure::getGold () { return gold; }

