#ifndef __SMALL_HOARD_H__
#define __SMALL_HOARD_H__
#include "treasure.h"
class Object;
class Type;
class Player;

class Small_Hoard final:public Treasure {
	public:
	bool visit (Object &object, Type type);
	bool be_visit (Player &player, Type type);
	Small_Hoard (int posx, int posy, Style style, int gold);
};

#endif 

