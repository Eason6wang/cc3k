#include"enemy.h"
#include "info.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "buff.h"
#include "visitexcept.h"
using namespace std;
#include <iostream>

Enemy::Enemy(int hp, int atk, int def, int row, int col, Style style):
  Character{hp, atk, def, row, col, style} {}

bool Enemy::be_visit(Shade& player, Type type){ // default
    if (type == MOVE) return false;
    if(type == ATTACK){
		cout << "shade be attacked" << endl;
  	int damage = getDamage(player.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = "PC deals " + std::to_string(damage) + " damage to " + 
	    getString(Object::getPos().style) + to_string(getInfo().hp) + ". ";
  	player.getPlayerInfo().action.assign(newAction);
	if(getInfo().hp <= 0){
	    int gold = getRandom(1, 2);
	    gold == 1 ?  throw VisitExcept{SMALL_HOARD,1} :
	                 throw VisitExcept{NORMAL_HOARD,1};
	} else {
	  return true;
	} 
    }
	return false;
}

//below has not been changed
bool Enemy::be_visit(Drow& drow, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = getDamage(drow.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Vampire& vampire, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = getDamage(vampire.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Troll& troll, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = getDamage(troll.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Goblin& goblin, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = getDamage(goblin.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
/*bool Enemy::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
*/

/*bool Enemy::be_visit(Player& player, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = getDamage(player.getInfo().atk, enemy.getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
*/

//
//
//bool be_visit(Drow& player, Type t){
//  int damage = getDamage(player.getInfo().atk, info.def);
//  info.hp -= damage;
//  return false;
//}
//
//
//bool be_visit(Vampire& player, Type t){
//  int damage = getDamage(player.getInfo().atk, info.def);
//  info.hp -= damage;
//  return false;
//}
//
//
//bool be_visit(Troll& player, Type t){
//  int damage = getDamage(player.getInfo().atk, info.def);
//  info.hp -= damage;
//  return false;
//}
//
//
//bool be_visit(Goblin& player, Type t){
//  int damage = getDamage(player.getInfo().atk, info.def);
//  info.hp -= damage;
//  return false;
//}
//
//
