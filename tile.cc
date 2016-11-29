#include "tile.h"
	
Tile::Tile(int posx, int posy):Cell{posx, posy, TILE} {}

bool Tile::be_visit (Character &character, Type type){
	if (type == ATTACK) return false;
	if (type == MOVE) return true;
    return false;
}