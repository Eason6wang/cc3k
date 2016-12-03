#include"dragon.h"
#include "info.h"
#include "shade.h"


Dragon::Dragon(int r, int c): Enemy(150,20,20,r,c, DRAGON) {}



bool Dragon::visit(Object& obj, Type type){
	return obj.be_visit(*this, type);
}

/*
bool Dragon::be_visit(Shade& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, enemy.getInfo().def);
  enemy.getInfo().hp -= damage;
  return false;
}



bool Dragon::be_visit(Drow& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}

bool Dragon::be_visit(Vampire& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}

bool Dragon::be_visit(Troll& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}
bool Dragon::be_visit(Goblin& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}

bool be_visit(Human& enemy, Type t) {
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool be_visit(Dwarf& enemy, Type t) {
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool be_visit(Halfling& enemy, Type t) {
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool be_visit(Elf& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}
 

bool be_visit(Orc& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}
 

bool be_visit(Dragon& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}
 

bool be_visit(Merchant& enemy, Type t){
  int damage = getDamage(enemy.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}
*/

