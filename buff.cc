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

// dragon attack is different

bool be_attack(Player &player, Enemy &enemy){
    int extraDamage = 1;
    if(player.getPos().style == GOBLIN && enemy.getPos().style == ORC)//orc case
	 extraDamage = 1.5;
    int damage = extraDamage * getDamage(enemy.getInfo().atk, player.getInfo().def);
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
    int &enemyHp = enemy.getInfo().hp;
    int &playerHp = player.getInfo().hp;
    string enemyType =  getString(enemy.getPos().style); 
    string playerType = getString(player.getPos().style);
    if(enemyType == "dwarf" && playerType == "vampire") playerHp -= 10; //dwarf case
	  // vampire here has already gained 5 hp
    int extraDamage = 1;
    if(enemyType == "elf" && playerType != "drow") extraDamage = 2;//elf case
    int damage = extraDamage * getDamage(player.getInfo().atk, enemy.getInfo().def);
    int randomnum =  getRandom(1, 2);
    if(enemyType == "halfling"){ //halfling case
       if(randomnum == 1){
          enemyHp -= damage;
       }
    }
    std::string newAction;
    if(enemyHp > 0){
       newAction = "PC deals (" + std::to_string(damage) + ") damage to "
             + enemyType + "(" + std::to_string(enemyHp)  + "). ";
    } else {
	newAction = "PC kills " + enemyType  + ". ";
    }
    player.getPlayerInfo().action += newAction;
    if(enemyHp <= 0){
	if(playerType == "goblin") player.getPlayerInfo().gold += 5;//goblin case
	if(enemyType == "human") throw VisitExcept{"normal_hoard", 2};// human case
	 randomnum == 1 ?  throw VisitExcept{"small_hoard",1}:    // normal case
	              throw VisitExcept{"normal_hoard",1};
    } else {
	return true;
    }
}



