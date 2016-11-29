#ifndef __NORMAL_HOARD_H__
#define __NORMAL_HOARD_H__
#include "treasure.h"
#include "type.h"
class Object;
class Shade;

class Normal_Hoard final:public Treasure {
	public:
	bool be_visit (Shade &shade, Type type);
	Normal_Hoard (int row, int col);
};

#endif 

