#ifndef __ITEM_H__
#define __ITEM_H__
#include "object.h"

class Item :public Object {
	public:
	Item(int posx, int posy, Style style)
		:Object{posx, posy, style} {}
	virtual ~Item() = default;
};

#endif
