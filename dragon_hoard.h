#ifndef __DRAGON_HOARD_H__
#define __DRAGON_HOARD_H__
#include "treasure.h"
#include "type.h"
class Object;

class Dragon_Hoard final:public Treasure {
	public:
	Dragon_Hoard (int row, int col);
};

#endif
