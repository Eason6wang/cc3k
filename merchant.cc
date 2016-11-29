#include"merchant.h"

Merchant::Merchant(int r, int c) :
  Enemy{30, 70, 5, r, c, MERCHANT} {}

bool Merchant::revenge = false;
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
