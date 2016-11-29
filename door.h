#ifndef __DOOR_H__
#define __DOOR_H__
#include "cell.h"
#include "style.h"
#include "type.h"
class Character;

class Door final:public Cell {
	public:
    Door(int, int);
	bool be_visit (Character &character, Type type);
};

#endif
