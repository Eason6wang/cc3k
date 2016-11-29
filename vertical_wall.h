#ifndef __VERTICAL_WALL_H__
#define __VERTICAL_WALL_H__
#include "cell.h"

class Vertical_Wall final:public Cell {
	public:
	Vertical_Wall (int posx, int posy) :Cell{posx, posy, VERTICAL_WALL} {}
};

#endif
