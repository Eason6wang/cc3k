#include"enemy.h"
#include "info.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
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
	std::string newAction = "PC deals " + std::to_string(damage) +
	           " damage to " + getString(Object::getPos().style) + ". ";
  	player.getPlayerInfo().action.assign(newAction);
	/*if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	} */
    }
	return false;
}

//below has not been changed
bool Enemy::be_visit(Drow& drow, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(drow.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Vampire& vampire, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(vampire.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Troll& troll, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(troll.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
bool Enemy::be_visit(Goblin& goblin, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(goblin.getInfo().atk, this->getInfo().def);
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
