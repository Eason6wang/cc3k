#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "cell.h"
#include "style.h"
class Character;

class Passage final:public Cell {
	public:
    Passage (int posx, int posy);
	bool be_visit (Character &character, Type type);
};

#endif
