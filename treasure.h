#ifndef __TREASURE_H__
#define __TREASURE_H__
#include "item.h"
#include "type.h"
class Object;

class Treasure :public Item {
	int gold;
	public:
	int getGold ();
	Treasure (int pos, int posy, Style style, int gold);
	virtual ~Treasure () = default;
};

#endif
