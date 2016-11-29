#include"merchant.h"
#include "shade.h"

Merchant::Merchant(int row, int col):
  Enemy{140, 20, 20, row, col, MERCHANT}{}

bool Merchant::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}

bool Merchant::be_visit(Shade& shade, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(shade.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}

/*
bool Merchant::visit_object(Type t){
	return false;
}

bool Merchant::visit(Object& obj, Type t){
  if(revenge){
    obj.be_visit(*this);
    return false;
  }
  return false;
}
//be_visit
bool Merchant::be_visit(Shade& player, Type t){
  revenge = true;
  int damage = getDamage(player.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}

bool Merchant::be_visit(Drow& player, Type t){
  revenge = true;
  int damage = getDamage(player.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool Merchant::be_visit(Vampire& player, Type t){
  revenge = true;
  int damage = getDamage(player.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool Merchant::be_visit(Troll& player, Type t){
  revenge = true;
  int damage = getDamage(player.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}


bool Merchant::be_visit(Goblin& player, Type t){
  revenge = true;
  int damage = getDamage(player.getInfo().atk, info.def);
  info.hp -= damage;
  return false;
}

*/
