#include "door.h"


Door::Door(int posx, int posy):Cell(posx, posy, DOOR) {}

bool Door::be_visit (Character &character, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
