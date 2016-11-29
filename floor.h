#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include <string>
#include "type.h"
#include "object.h"
#include "display.h"
#include "chamber.h"
#include<memory>

class Floor{
	std::vector<std::vector<std::shared_ptr<Object>>> board; //the board
	std::shared_ptr thePlayer;
	std::shared_ptr theStair;
	std::vector<std::shared_ptr<Potion>> thePotion;
	std::vector<std::shared_ptr<Enemy> theEnemy;
	std::vector<std::shared_ptrTreasure> theTreasure;
	std::vector<Chamber> theChamber; //store the chamber
	std::shared_ptr<Object> tmp; 
	auto w; //display.
	auto p; //planar.
	int height;
	int width;
	bool stop;
	void enemyMove(int n);
	void clearFloor();
	void getRandom(int min, int max);
	public:	
	Floor();
	~Floor();
	
	void init(ifstream& file); // set up the board according to the given floor in the file.
	void setChamber(int r, int c, std::vector<shared_ptr<Object>> arr);
	void setPlayer(Player& p); // generate player.
	void setStairWay(); //generate stairway.
	void setPotion(); //generate potion
	void setTreasure(); //generate gold.
	void setEnemy(); //generate enemy.
	
	void floorVisit(std::string s, Type type);
	void stop();
	
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
