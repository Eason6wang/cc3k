#include "passage.h"
	
Passage::Passage(int posx, int posy):Cell{posx, posy, PASSAGE} {}

bool Passage::be_visit (Character &character, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
