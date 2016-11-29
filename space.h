#ifndef __SPACE_H__
#define __SPACE_H__
#include "cell.h"

class Space final:public Cell{
	public:
	Space (int posx, int posy):Cell{posx, posy, SPACE} {}
};

#endif
