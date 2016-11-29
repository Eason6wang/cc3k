#include "stair.h"
	
Stair::Stair (int posx, int posy):Cell{posx, posy, STAIR} {}

bool Stair::be_visit (Character &character, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
