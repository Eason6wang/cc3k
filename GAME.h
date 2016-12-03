#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#include "normal_gamecontroller.h"
#include "dlc_gamecontroller.h"

class Game{
	D_GameController d_game;
	N_GameController n_game;
	public:
	void selectVersion(std::string file);
};

#endif
