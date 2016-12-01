#include "passage.h"
	
Passage::Passage(int posx, int posy):Cell{posx, posy, PASSAGE} {}

bool Passage::be_visit (Shade& player, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Drow& player, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Vampire& player, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Troll& player, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Passage::be_visit (Goblin& player, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
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
/*
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
