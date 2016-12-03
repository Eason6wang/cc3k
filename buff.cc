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
#include "potion.h"

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


bool be_attack(Item &item, Player &player){ 
    string newAction = "PC cannot attack an Item. ";     
    player.getPlayerInfo().action += newAction;
    return false;
}




bool be_attack(Player &player, Enemy &enemy){
    string newAction;
    float extraDamage = 1;
    if(player.getPos().style == GOBLIN && enemy.getPos().style == ORC){
	//orc case
	 extraDamage = 1.5;
   	 newAction = "Orc does 50% more damage to PC. ";
    	 player.getPlayerInfo().action += newAction;
    }
    int damage = extraDamage * getDamage(enemy.getInfo().atk, player.getInfo().def);
    player.getInfo().hp -= damage;
    newAction = getString(enemy.getPos().style) + 
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
    Style enemyType =  enemy.getPos().style; 
    Style playerType = player.getPos().style;
    string newAction;
    if(enemyType == DWARF && playerType == VAMPIRE){
	 playerHp -= 5;
 	 newAction = "PC drops 5 HP because the Enemy is Dwarf. ";
    	player.getPlayerInfo().action += newAction;
	  //dwarf case
    } else if(playerType == VAMPIRE){
	 playerHp += 5;
	  // vampire case 
	  newAction = "PC gains 5 HP when attacking enemy. " ;
   	 player.getPlayerInfo().action += newAction;

    }
    int extraDamage = 1;
    if(enemyType == ELF && playerType != DROW){
	 extraDamage = 2;//elf case
	  newAction = "The Enemy(E) gets two attacks. " ;
   	 player.getPlayerInfo().action += newAction;
    }
    int damage = extraDamage * getDamage(player.getInfo().atk, enemy.getInfo().def);
    int randomnum =  getRandom(1, 2);
    if(enemyType == HALFLING){ //halfling case
       if(randomnum == 1){
          enemyHp -= damage;
       }else{
	 newAction = "PC unsuccessfully attack L(" + to_string(enemyHp) +  "). " ;
   	 player.getPlayerInfo().action += newAction;
	 return true;
       }
    } else {
	enemyHp -= damage;
    }
    if(enemyHp > 0){
       newAction = "PC deals (" + std::to_string(damage) + ") damage to "
             + getString(enemyType) + "(" + std::to_string(enemyHp)  + "). ";
    } else {
	newAction = "PC kills " + getString(enemyType)  + ". ";
    }
    player.getPlayerInfo().action += newAction;
    if(enemyHp <= 0){
	if(playerType == GOBLIN){
	     player.getPlayerInfo().gold += 5;//goblin case
	     newAction = "PC gains 5 gold from the slain enemy. " ;
   	     player.getPlayerInfo().action += newAction;
	}
	if(enemyType == HUMAN){
	     newAction = "Slain H drops 2 piles of gold. " ;
   	     player.getPlayerInfo().action += newAction;
	     throw VisitExcept{"normal_hoard", 2};// human case

	}
	 randomnum == 1 ?  throw VisitExcept{"small_hoard",1}:    // normal case
	              throw VisitExcept{"normal_hoard",1};
    } else {
	return true;
    }
}

//for potion

bool be_pick_up(Potion &potion,Player &player) {
    int changeHp = 0;
    int changeAtk = 0;
    int changeDef = 0;
    Style style = potion.getPos().style;
    if(style == RESTORE_HEALTH){
	changeHp = 10;
    } else if (style == BOOST_ATK){
	changeAtk = 5;
    } else if (style == BOOST_DEF){
	changeDef = 5;
    } else if(style == POISON_HEALTH){
	changeHp = -10;
    } else if(style == WOUND_ATK){
	changeAtk = -5;
    } else if(style == WOUND_DEF){
	changeDef = -5;
    }
    // drow case
    string newAction;
    if(player.getPos().style == DROW){
	changeHp *= 1.5;
	changeAtk *= 1.5;
	changeDef *= 1.5;
	newAction = "The Potion effect is magnified by 1.5 in Drow. ";
        player.getPlayerInfo().action += newAction;

    }
    int playerhp = player.getInfo().hp;
    int playeratk = player.getInfo().atk;
    int playerdef = player.getInfo().def;
    shared_ptr<Potion> &playerPotion = player.getPlayerInfo().potion;
    shared_ptr<Potion> newpotion = make_shared<Potion>(0, 0, SPACE);
    newpotion->modify().hp = playerhp + changeHp;
    newpotion->modify().atk = playeratk + changeAtk;
    newpotion->modify().def = playerdef + changeDef;
    newpotion->getPotion() = playerPotion;
    playerPotion = newpotion;
    newAction = "PC uses " + getString(potion.getPos().style) + ". ";     
    player.getPlayerInfo().action += newAction;
    throw VisitExcept {"pickup_potion", 0};
}

bool be_pick_up(Enemy &enemy, Player &player){
    string newAction = "PC cannot pick up an Enemy. ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}

bool be_pick_up(Player &player, Enemy &enemy){ 
    return false; 
}

bool be_pick_up(Treasure &treasure, Player &player){
    string newAction = "It is too far for PC to fetch. ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}


// for gold

bool be_go_over(Treasure &treasure,Player &player) {
    	string newAction = "PC picks up a " + getString(treasure.getPos().style) + ". ";     
    	player.getPlayerInfo().action += newAction;
  	player.getPlayerInfo().gold += treasure.getGold();
	throw VisitExcept{"pickup_gold", 0};
}

bool be_go_over(Potion &potion, Player &player){
    string newAction = "PC cannot go over a Potion. ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}

bool be_go_over(Enemy &enemy, Player &player){
    string newAction = "PC cannot go over an Enemy. ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}

bool be_go_over(Player &player, Enemy &enemy){ 
    return false; 
}





