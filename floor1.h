#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include <string>
#include "type.h"
#include "object.h"
#include "display.h"
#include "chamber.h"
#include "player.h"

class Window;
class Panel;
class Player;
class Enemy;

class Floor{
	std::vector<std::vector<std::shared_ptr<Object>>> board; //the board
	std::shared_ptr<Player> thePlayer;
//	std::shared_ptr theStair;
//	std::vector<std::shared_ptr<Potion>> thePotion;
	std::vector<std::shared_ptr<Enemy>> theEnemy;
//	std::vector<std::shared_ptrTreasure> theTreasure;
	std::vector<Chamber> theChamber; //store the chamber
//	std::shared_ptr<Object> tmp;
    std::shared_ptr<Window> w; //display.
    std::shared_ptr<Panel> p; //planar.
	int height;
	int width;
	bool stop;
	bool enemyMove(int n);
	void clearFloor();
	int getRandom(int min, int max);
	public:	
	Floor();
	//~Floor();
	
    void init(std::string file); // set up the board according to the given floor in the file.
    void setChamber(int r, int c, std::vector<std::shared_ptr<Object>*>& arr);
	void setPlayer(); // generate player.
	void setStair(); //generate stairway.
	void setPotion(); //generate potion
	void setTreasure(); //generate gold.
	void setEnemy(); //generate enemy.
    
	void floorVisit(std::string s, Type type);
	void pause();
	
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
