#include"enemy.h"
#include "info.h"
#include "shade.h"
using namespace std;


Enemy::Enemy(int hp, int atk, int def, int row, int col, Style style):
  Character{hp, atk, def, row, col, style} {}

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
