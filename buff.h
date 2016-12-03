#ifndef _BUFF_H_
#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <memory>
#include "type.h"
#include "treasure.h"
class VisitExcept;


class Object;
class Player;
class Enemy;

void clearScreen();

int getRandom(int min, int max);

std::string messageOut(std::string message);

int getDamage(int, int);


bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);

int distance(int r1, int c1, int r2, int c2);

//void normal_enemy_move();
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
#endif
