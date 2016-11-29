#ifndef __TILE_H__
#define __TILE_H__
#include "cell.h"
#include "style.h"
class Character;

class Tile final:public Cell {
	public:
    Tile (int posx, int posy);
	bool be_visit (Character &character, Type type);
};

#endif
