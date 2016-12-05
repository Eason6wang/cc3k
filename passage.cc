#include "passage.h"
#include "worgen.h"
#include "forsaken.h"
#include "bloodelf.h"
#include "eason.h"
#include "nightelf.h"


Passage::Passage(int posx, int posy):Cell{posx, posy, PASSAGE} {}

bool Passage::be_visit (Shade& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Drow& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Vampire& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Troll& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Goblin& player, Type type){
	if (type == MOVE) return true;
    return false;
}

bool Passage::be_visit (Eason& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (NightElf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (ForSaken& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Worgen& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}



/*
bool Passage::be_visit (Human& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Dwarf& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Halfling& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Orc& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Elf& enemy, Type type){
	if (type == ATTACK) return false;

	if (type == MOVE) return true;
    return false;
}

bool Passage::be_visit (Dragon& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Merchant& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
*/
