#include"player.h"
#include "potion.h"
#include <string>
#include "buff.h"

#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "dragon.h"
/*#include "merchant.h"
#include "small_hoard.h"
#include "normal_Hoard.h"
#include "dragon_hoard.h"
#include "merchant_Hoard.h"
#include "restore_Hearlth.h"
#include "boost_atk.h"
#include "boost_def.h"
#include "poison_health.h"
#include "wound_atk.h"
#include "wound_def"
*/
using namespace std;

Player::Player(int hp, int atk, int def, int row, int col, Style style):
Character{hp, atk, def, row, col, style}, playerInfo{0, 1, nullptr, ""}{}

void Player::levelUp(){
    playerInfo.potion = nullptr;
  playerInfo.level++;
}


bool Player::isvisible(){
    return visible;
}

Info& Player::getInfo () {
    if(!getPlayerInfo().potion){
      return Character::getInfo();
    } else {
	auto &modifyInfo = getPlayerInfo().potion->modify();
	Character::getInfo().hp = modifyInfo.hp;
	return modifyInfo;
    }
}

PlayerInfo& Player::getPlayerInfo(){
  return playerInfo;
}


bool Player::be_visit(Human& enemy, Type type){
/*    if (type == MOVE) return false;
    if(type == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = getString(enemy.getPos().style) 
		+" deals " + std::to_string(damage) + " damage to PC. ";
  	playerInfo.action += newAction;
	if(getInfo().hp <= 0){
	  throw true;// will be catch to display something
	} else {
	  return true;
	} 
  }
	return false;
	*/
  return be_visit_by(*this, enemy, type);
}

bool Player::be_visit(Orc& enemy, Type type){
	/*if (type == MOVE) return false;
    if(type == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = getString(enemy.getPos().style) 
		+" deals " + std::to_string(damage) + " damage to PC. ";
  	playerInfo.action += newAction;
	if(getInfo().hp <= 0){
	  throw true;// will be catch to display something
	} else {
	  return true;
	} 
  }
	return false;
	*/

 return be_visit_by(*this, enemy, type);

}
bool Player::be_visit(Dwarf& enemy, Type type){
/*	if (type == MOVE) return false;
    if(type == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = getString(enemy.getPos().style) 
		+" deals " + std::to_string(damage) + " damage to PC. ";
  	playerInfo.action += newAction;
	if(getInfo().hp <= 0){
	  throw true;// will be catch to display something
	} else {
	  return true;
	} 
 
  }
	return false;*/
 return be_visit_by(*this, enemy, type);


}
bool Player::be_visit(Halfling& enemy, Type type){
/*	if (type == MOVE) return false;
    if(type == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = getString(enemy.getPos().style) 
		+" deals " + std::to_string(damage) + " damage to PC. ";
  	playerInfo.action += newAction;
	if(getInfo().hp <= 0){
	  throw true;// will be catch to display something
	} else {
	  return true;
	} 
 
  }
	return false;
	*/
 return be_visit_by(*this, enemy, type);

}
bool Player::be_visit(Elf& enemy, Type type){
	/*if (type == MOVE) return false;
    if(type == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, this->getInfo().def);
  	this->getInfo().hp -= damage;
	std::string newAction = getString(enemy.getPos().style) 
		+" deals " + std::to_string(damage) + " damage to PC. ";
  	playerInfo.action += newAction;
	if(getInfo().hp <= 0){
	  throw true;// will be catch to display something
	} else {
	  return true;
	} 
  }
	return false;
	*/


 return be_visit_by(*this, enemy, type);
}


bool Player::be_visit(Dragon& enemy, Type type){
 return be_visit_by(*this, enemy, type);

}

bool Player::be_visit(Merchant& enemy, Type type){

 return be_visit_by(*this, enemy, type);

}
