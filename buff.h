//#ifndef _BUFF_H_
//#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <memory>
#include "type.h"
class VisitExcept;

class Object;
class Player;
class Enemy;

void clearScreen();

int getRandom(int min, int max);

int getDamage(int, int);


bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);


//template
template<typename Bevisit , typename Visit , typename Type>
bool be_visit_by(Bevisit & v1, Visit & v2, Type t){
    if(t == ATTACK){
	return be_attack(v1, v2);
    }
    return false;
}

template<typename PlayerType>
bool be_visit_health_potion (PlayerType player, Type type, int num) {
	if (type == PICKUP) {
		player.getInfo().hp += num;
		throw VisitExcept {"pickup_potion", 0};
	} else return false;
}


bool be_attack(Player &player, Enemy &enemy);

bool be_attack(Enemy &enemy, Player &player);  
//#endif
