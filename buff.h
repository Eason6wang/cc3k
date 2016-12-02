#ifndef _BUFF_H_
#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <memory>
class Object;
class Player;
class Enemy;

void clearScreen();

int getRandom(int min, int max);

int getDamage(int, int);


bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);


//template
template<typename Visit, typename Bevisit, typename Type>
bool be_visit_by(Visit & v1, Bevisit & v2, Type t);



bool be_attack(Player &player, Enemy &enemy);

bool be_attack(Enemy &enemy, Player &player);  
#endif
