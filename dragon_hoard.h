#ifndef __DRAGON_HOARD_H__
#define __DRAGON_HOARD_H__
#include "treasure.h"
class Object;
class Type;

class Dragon_Hoard final:public Treasure {
	public:
	bool be_visit (Player &player, Type type) override;
	Dragon_Hoard (int posx, int posy, Style style, int gold)
		:Treasure{posx, posy, style, gold} {}

#endif
