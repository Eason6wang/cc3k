#ifndef __STAIR_H__
#define __STAIR_H__
#include "cell.h"
class Character;

class Stair final:public Cell {
	public:
    Stair (int posx, int posy);
	bool be_visit (Character &character, Type type);
};

#endif
