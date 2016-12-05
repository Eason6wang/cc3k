#include"horizontal_wall.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "aaron.h"



bool Horizontal_Wall::be_visit (Aaron& player, Type type){

	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Horizontal_Wall::be_visit (Shade& player, Type type){

	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Horizontal_Wall::be_visit (Drow& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}

bool Horizontal_Wall::be_visit (Vampire& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
bool Horizontal_Wall::be_visit (Troll& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}

bool Horizontal_Wall::be_visit (Goblin& player, Type type){
	if (type == MOVE){
	    player.getPlayerInfo().action += "PC cannot go through the wall. ";
	}
    return false;
}
