#ifndef _BUFF_H_
#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <memory>
#include "type.h"
<<<<<<< HEAD
#include "style.h"
class VisitExcept;
class Potion;
=======
#include "treasure.h"
class VisitExcept;


>>>>>>> be49fa4081771e22ffc102513bb4b16f0ac02bba
class Object;
class Player;
class Enemy;
class Item;

void clearScreen();

int getRandom(int min, int max);

std::string messageOut(std::string message);

int getDamage(int, int);


bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);

int distance(std::shared_ptr<Object> ob1, std::shared_ptr<Object> ob2);

//void normal_enemy_move();
//template
template<typename Bevisit , typename Visit , typename Type>
bool be_visit_by(Bevisit & v1, Visit & v2, Type t, Style style = SPACE){
    if(t == ATTACK){
	return be_attack(v1, v2);
    }
    if(t == PICKUP){
	return be_pick_up(v1, v2, style);
    }
//move
    return false;
}


bool be_attack(Player &player, Enemy &enemy);

bool be_attack(Enemy &enemy, Player &player);  

bool be_pick_up(Potion &potion, Player &player, Style style);

bool be_pick_up(Enemy &enemy, Player &player, Style style);
bool be_pick_up(Player &player, Enemy &enemy, Style style);
bool be_attack(Item &item, Player &player);
#endif
