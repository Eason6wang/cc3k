#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include "floor1.h"

class Object;

class GameController{
	Floor floor;
	public:
	//GameController();
	//~GameController();

	void play(std::string file = "plainfloor.txt");
};

#endif
