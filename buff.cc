#include "buff.h"
#include <curses.h>
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
#include "merchant.h"
#include <utility>
#include "dragon.h"
//#include "subject.h"

using namespace std;


vector<pair<int, int>> findChar(vector<vector<char>> s, char c){
	vector<pair<int, int>> rv;
	for(int i = 0; i < s.size(); i++){
		for (int j = 0; j < s[0].size(); j++){
			if (s[i][j] == c) {
				pair<int,int> p = make_pair(i,j);
				rv.emplace_back(p);
			}
		}
	}
	return rv;
}

void colorLayer(vector<pair<int, int>> thechar, char c){
	for(auto n: thechar) {
		mvaddch(n.first,n.second,c);
	}
}

/*void colorWindow(string s) {
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	//init_pair(6, COLOR_BLUE, COLOR_BLACK);
	vector<int> player = findChar(s,'@');
	vector<int> gold = findChar(s, 'G');
	vector<int> potion = findChar(s, 'P');
	vector<int> stair = findChar(s, '\\');
	vector<int> door = findChar(s, '+');

	CWidget::mvaddstr(0,0, s.c_str);

	attron(COLOR_PAIR(1));
	colorLayer(potion, s);
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	colorLayer(door, s);
	attroff(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(3));
	colorLayer(stair, s);
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(4));
	colorLayer(player, s);
	attroff(COLOR_PAIR(4));
	
	attron(COLOR_PAIR(5));
	colorLayer(gold, s);
	attroff(COLOR_PAIR(5));
}	*/


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


/*void rectangle(int height, int width){
	ofstream out{"randomfloor.txt"};
	for(int i = 0; i < height; i++){
		if (i == 0 || i == height -1) {
			for(int t = 0; t < width; t++){
				if (t == 0|| t == width-1) {
					out << '|';
				} else out << '-';
				out << endl;
			}
		} else {
			for(int j = 0; j < width; j++){
				if(j == 0 || j == width -1){
					out << '|';
				} else out << '.';
				out << endl;
			}
		}
	}
	out.close();
}*/


//void randomFloor(){



//}



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
	newAction = "PC smashes " + getString(enemyType)  + ". ";
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
	if(enemyType == MERCHANT){
	     throw VisitExcept{"merchant_hoard", 1};// merchant case
	}
	if(enemyType == DRAGON){
	   //dragon case
	   enemy.notifyObservers();
	   return true;
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

string direction(Object &bevisit, Object &visit){
    int x1 = bevisit.getPos().posx;
    int y1 = bevisit.getPos().posy;
    int x2 = visit.getPos().posx;
    int y2 = visit.getPos().posy;
    if((x1 - x2) == -1 && (y1 - y2) == -1){
	return "Northwest";
    }
    if((x1 - x2) == 0 && (y1 - y2) == -1){
	return "North";
    }
    if((x1 - x2) == 1 && (y1 - y2) == -1){
	return "Northeast";
    }
    if((x1 - x2) == -1 && (y1 - y2) == 0){
	return "West";
    }
    if((x1 - x2) == 1 && (y1 - y2) == 0){
	return "East";
    }
    if((x1 - x2) == -1 && (y1 - y2) == 1){
	return "Southwest";
    }
    if((x1 - x2) == 0 && (y1 - y2) == 1){
	return "South";
    }
    if((x1 - x2) == 1 && (y1 - y2) == 1){
	return "Southeast";
    }
}
 

bool be_go_over(Treasure &treasure,Player &player) {
    	string newAction = "PC moves " + direction(treasure, player) + 
	         " and picks up a " + getString(treasure.getPos().style) + ". ";     
    	player.getPlayerInfo().action += newAction;
  	player.getPlayerInfo().gold += treasure.getGold();
	throw VisitExcept{"pickup_gold", 0};
}


bool be_go_over(Potion &potion, Player &player){
    string newAction = "PC moves " + direction(potion,player) +
                      " and sees an unknown Potion. ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}

bool be_go_over(Enemy &enemy, Player &player){
    string newAction = "PC moves " + direction(enemy, player) + 
                " and sees a " + getString(enemy.getPos().style) + ". ";     
    player.getPlayerInfo().action += newAction;
    return false; 
}

bool be_go_over(Player &player, Enemy &enemy){
    return false; 
}





