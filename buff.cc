#include "buff.h"
#include "object.h"
#include"player.h"
#include"enemy.h"
#include <string>
#include "character.h"
#include "playerinfo.h"
#include "type.h"
#include "style.h"
#include "visitexcept.h"


using namespace std;
void clearScreen(){
	for(int i = 0; i < 100; i++){
		cout << endl;
	}
}

int getRandom(int min, int max){
	int n = max - min + 1;
	int rn = rand() % n + min;
	return rn;
}

int getDamage(int atk, int def) {
	return ((100 * atk) / (100 + def));
}

bool compare(shared_ptr<Object> ob1, shared_ptr<Object> ob2){
	if (ob1->getPos().posy < ob2->getPos().posy) {
		return true;
	} else if (ob1->getPos().posy == ob2->getPos().posy) {
		if (ob1->getPos().posx < ob2->getPos().posx){
			return true;
		} else if (ob1->getPos().posx == ob2->getPos().posy) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}


//template



bool be_attack(Player &player, Enemy &enemy){
    int damage = getDamage(enemy.getInfo().atk, player.getInfo().def);
    player.getInfo().hp -= damage;
    std::string newAction = getString(enemy.getPos().style) + 
           " deals (" + std::to_string(damage) + ") damage to PC. ";
    player.getPlayerInfo().action += newAction;
    if(player.getInfo().hp <= 0){
	throw VisitExcept{"deadplayer", 0};
    } else {
	return true;
    }
}

bool be_attack(Enemy &enemy, Player &player){  
  int damage = getDamage(player.getInfo().atk, enemy.getInfo().def);
    int &enemyHp = enemy.getInfo().hp;
    enemyHp -= damage;
    std::string newAction;
    if(enemyHp > 0){
       newAction = "PC deals (" + std::to_string(damage) + ") damage to "
             + getString(enemy.getPos().style) + "(" + std::to_string(enemyHp)  + "). ";
    } else {
	newAction = "PC kills " + getString(enemy.getPos().style)  + ". ";
    }
    player.getPlayerInfo().action += newAction;
    if(enemyHp <= 0){
 	int gold = getRandom(1, 2);
	 gold == 1 ?  throw VisitExcept{"small_hoard",1}:
	              throw VisitExcept{"normal_hoard",1};
    } else {
	return true;
    }
}
