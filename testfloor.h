#ifndef _N_FLOOR_H_
#define _N_FLOOR_H_
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "type.h"
#include "object.h"
#include "chamber.h"
#include "player.h"

class Window;
class Panel;
class Player;
class Enemy;
class Display;

class T_Floor{
int :
	std::vector<std::vector<std::shared_ptr<Object>>> board; //the board
	std::shared_ptr<Player> thePlayer;
	std::vector<std::shared_ptr<Enemy>> theEnemy;
	Display& theDisplay;
	int height;
	int width;
	bool stop;
	bool enemyMove(int n, std::vector<bool>& possibility);
	public:	
	T_Floor(Display& display);
	void floorVisit(std::string s, Type type);
	void clearFloor(bool cleanPlayer);
    void init(ifstream& file); // set up the board according to the given floor in the file.
    
	void pause();
	std::string outPut();
	
	friend std::ostream &operator<<(std::ostream &out, const T_Floor &f);
};

#endif
