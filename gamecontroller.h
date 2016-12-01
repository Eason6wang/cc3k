#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include "floor1.h"
#include "display.h"

class Object;

class GameController{
	Display display;
	Floor floor;
	public:
	GameController();
	//~GameController();
	void startGame(std::string file = "plainfloor.txt");
	void wasdPlay(std::string file);
	void play(std::string file);
};

#endif
