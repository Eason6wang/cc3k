#ifndef __HORIZONTAL_WALL_H__
#define __HORIZONTAL_WALL_H__
#include "cell.h"

class Horizontal_Wall final:public Cell {
	public:
	Horizontal_Wall (int posx, int posy):Cell{posx, posy, HORIZONTAL_WALL} {}
};

#endif
