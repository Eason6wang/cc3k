#include "tile.h"
	
Tile::Tile(int posx, int posy):Cell{posx, posy, TILE} {}

bool Tile::be_visit (Shade& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Drow& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Vampire& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Troll& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Goblin& player, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Human& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Dwarf& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Halfling& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Orc& enemy, Type type){
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Elf& enemy, Type type){
	if (type == MOVE) return true;

    return false;
}
bool Tile::be_visit (Small_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
bool Tile::be_visit (Normal_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
bool Tile::be_visit (Merchant_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
bool Tile::be_visit (Dragon_Hoard &hoard, Type type) {
	if (type == MOVE) return true;
	return false;
}
/*
bool Tile::be_visit (Dragon& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}
bool Tile::be_visit (Merchant& enemy, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}


bool Tile::be_visit(Normal_Hoard& treasure, Type type){
	return true;
}
*/
