#ifndef CHARACTER_H
#define CHARACTER_H

#include"info.h"
#include"object.h"

struct PlayerInfo;

class Character: public Object{
    Info information;
	protected:
	int getDamage(int atk, int def);
	public:
	Character(int hp, int atk, int def, int row, int col, Style style);
    Info& getInfo();
	virtual ~Character() = default;
//    virtual PlayerInfo getPlayerInfo() = 0;
};




#endif
