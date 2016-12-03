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

string messageOut(string message){
	string s = "\n" + message + "\n";
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

int distance(int r1,int c1, int r2, int c2){
	int ri = abs(r1 - r2) + abs(c1 - c2);
	return ri;
}


/*bool smart_enemyMove(int n, vector<bool>& possibility) {
	int r = theEnemy[n]->getPos().posy;
	int c = theEnemy[n]->getPos().posx;
	int target_r, target_c;
	int i = getRandom(1,8); //0 means the enemy don't move this round(don't know if it is necessary).
	if (i == 1) {
		target_r = r-1;
		target_c = c;
		possibility[i] = true;
	} else if (i == 2) {
		target_r = r+1;
		target_c = c;
		possibility[i] = true;
	} else if (i == 3) {
		target_r = r;
		target_c = c+1;
		possibility[i] = true;
	} else if (i == 4) {
		target_r = r;
		target_c = c-1;
		possibility[i] = true;
	} else if (i == 5){
		target_r = r-1;
		target_c = c+1;
		possibility[i] = true;
	} else if (i == 6){
		target_r = r-1;
		target_c = c-1;
		possibility[i] = true;
	} else if (i == 7){
		target_r = r+1;
		target_c = c+1;
		possibility[i] = true;
	} else {
		target_r = r+1;
		target_c = c-1;
		possibility[i] = true;
	}
    if (distance(player_r, player_c, target_r, target_c) < 
			distance(player_r, player_c, r,c) || 
			!theEnemy[n]->getPos().sameChamber){ //only trace when in same chamber  move when distance.
		if (theEnemy[n]->visit(*board[target_r][target_c], MOVE)){
			swap(theEnemy[n]->getPos().posx, board[target_r][target_c]->getPos().posx);
			swap(theEnemy[n]->getPos().posy, board[target_r][target_c]->getPos().posy);
			swap(board[r][c], board[target_r][target_c]);
			theDisplay.w->notify(*theEnemy[n]);
			theDisplay.w->notify(*board[r][c]);
			return true;
		} else if (!(possibility[1] &&  possibility[2] &&  possibility[3] &&
			   	possibility[4] && possibility[5] && possibility[6] &&
			   	possibility[7] && possibility[8])) {
			enemyMove(n, possibility);
		} else {
		//	cout << getString(theEnemy[n]->getPos().style) << endl;
	//		cout << "someone is stucked" << endl;
			return false;
		}
		 return false; //still need to check here.
	} else {
		enemyMove(n, possibility);
	}
}*/

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
    } else {
	enemyHp -= damage;
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



