#include"player.h"

/*#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "dragon.h"
#include "merchant.h"
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
Character{hp, atk, def, row, col, style}, playerInfo{0, 1, ""}{}

void Player::levelUp(){
  playerInfo.level++;
}

PlayerInfo& Player::getPlayerInfo(){
  return playerInfo;
}


// for enemy
/*
bool Player::be_visit(Human& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = "H deals " + ss.str() " damage to PC. ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}

bool Player::be_visit(Dwarf& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}


bool Player::be_visit(Halfling& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}
bool Player::be_visit(Elf& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}
bool Player::be_visit(Orc& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}

bool Player::be_visit(Dragon& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}

bool Player::be_visit(Merchant& enemy, Type t){
  if(t == ATTACK){
  	int damage = getDamage(enemy.getInfo().atk, info.def);
  	info.hp -= damage;
 	sstream ss;
 	ss << damage;
  	string newAction = enemy.getPos().style + " deals " + ss.str() " damage to " + getPos().style + ". ";
  	playerInfo.action += newAction;
	if(info.hp <= 0){
	  //throw
	} else {
	  return false;
	}
  }
}

// for postion
bool Player::be_visit(Small_Hoard& , Type t) {
  playerInfo.gold += treasure
}

bool Player::be_visit(Normal_Hoard& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}
 
bool Player::be_visit(Merchant_Hoard& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}
 
bool Player::be_visit(Dragon_Hoard& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}
 
bool Player::be_visit(Restore_Health& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}
 
bool Player::be_visit(Boost_Atk& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}

bool Player::be_visit(Boost_Def& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}

bool Player::be_visit(Poison_Health& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}

bool Player::be_visit(Wound_Atk& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}
 
bool Player::be_visit(Wound_Def& , Type t){
  int damage = getDamage(enemy.info.atk, info.def);
  info.hp -= damage;
}*/
