#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"
class Object;
class Type;

class Treasure :public Item {
	int gold;
	public:
	int getGold ();
	bool visit (Object &object, Type type);
	Treasure (int pos, int posy, Style style, int gold);
	virtual ~Treasure () = default;
};

#endif
