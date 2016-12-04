#include <iostream>
#include <cmath>
#include <algorithm>
#include "testfloor.h"
#include "type.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "style.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

#include "restore_health.h"
#include "boost_atk.h"
#include "boost_def.h"
#include "poison_health.h" 
#include "wound_atk.h" 
#include "wound_def.h"
	
#include "cell.h"
#include "space.h"
#include "vertical_wall.h"
#include "horizontal_wall.h"
#include "door.h"
#include "tile.h"
#include "passage.h"
#include "stair.h"

#include "window.h"
#include "panel.h"
#include "observer.h"

#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"

#include "item.h"
#include "treasure.h"
#include "small_hoard.h"
#include "normal_hoard.h"
#include "dragon_hoard.h"

#include "buff.h"
#include "display.h"
#include "visitexcept.h"
	using namespace std;
#include "curses.h"

class Enemy;


void T_Floor::clearFloor(bool cleanPlayer){
	//	cout << "enter clear" << endl;
	if (cleanPlayer){
		thePlayer = nullptr;
	} else {
		thePlayer->levelUp();
	}
	board.clear();
	theEnemy.clear();
	theChamber.clear();
//	cout << "out clear" << endl;
}
		

T_Floor::T_Floor(Display& display): theDisplay{display},height{25}, width{79}, stop{false} {}
		

void T_Floor::init(string file){
	//theDisplay.w = make_shared<Window>(file);
	string line;
	ifstream f {file};
	shared_ptr<Object> o;
	for (int i = 0; i < height; i++){
		vector<shared_ptr<Object>> arr;
		getline(f, line);
		for (int j = 0; j < width; j++){
			if (line[j] == '.') {
				o = make_shared<Tile>(j,i);
			} else if (line[j] == '-') {
				o = make_shared<Horizontal_Wall>(j,j);
			} else if (line[j] == '|') {
				o = make_shared<Vertical_Wall>(j,i);
			} else if (line[j] == '+') {
				o = make_shared<Door>(j,i);
			} else if (line[j] == '#') {
				o = make_shared<Passage>(j,i);
			} else if (line[j] == ' ') {
				o = make_shared<Space>(j,i);
			} else if (line[j] == '0') {
				o = make_shared<Restore_Health>(j,j);
			} else if (line[j] == '1') {
				o = make_shared<Boost_Atk>(j,i);
			} else if (line[j] == '2') {
				o = make_shared<Boost_Def>(j,i);
			} else if (line[j] == '3') {
				o = make_shared<Posion_Health>(j,i);
			} else if (line[j] == '4') {
				o = make_shared<Wound_Atk>(j,i);
			} else if (line[j] == '5') {
				o = make_shared<Wound_Def>(j,j);
			} else if (line[j] == '6') {
				o = make_shared<Normal_Hoard>(j,i);
			} else if (line[j] == '7') {
				o = make_shared<Small_Hoard>(j,i);
			} else if (line[j] == '8') {
				o = make_shared<Merchant_Hoard>(j,i);
			} else if (line[j] == '9'){
				o = make_shared<Dragon_Hoard>(j,i);
			
			} else if (line[j] == 'H') {
				o = make_shared<Human>(j,j);
			} else if (line[j] == 'W') {
				o = make_shared<Dwarf>(j,i);
			} else if (line[j] == 'E') {
				o = make_shared<Elf>(j,i);
			} else if (line[j] == 'O') {
				o = make_shared<Orc>(j,i);
			} else if (line[j] == 'M') {
				o = make_shared<Merchant>(j,i);
			} else if (line[j] == 'D') {
				o = make_shared<Dragon>(j,j);
			} else if (line[j] == 'L') {
				o = make_shared<Halfling>(j,i);
			} else { //'@'
				o = make_shared<Shade>(j,i);
				thePlayer = o;
			}
			o->attach(theDisplay.w);
			arr.emplace_back(o);
		}
		board.emplace_back(arr);
	}
}


	void T_Floor::floorVisit(string s, Type type){
		//cout << "enter floorvisit" << endl;
		int r = thePlayer->getPos().posy;
	//	cout << "here!!" << endl;
		int c = thePlayer->getPos().posx;
		int target_r, target_c;
	//	cout << "here " << endl;
		if (s == "no") {
			target_r = r-1;
			target_c = c;
		} else if (s == "so") {
			target_r = r+1;
			target_c = c;
		} else if (s == "ea") {
			target_r = r;
			target_c = c+1;
		} else if (s == "we") {
			target_r = r;
			target_c = c-1;
		} else if (s == "ne"){
			target_r = r-1;
			target_c = c+1;
		} else if (s == "nw"){
			target_r = r-1;
			target_c = c-1;
		} else if (s == "se"){
			target_r = r+1;
			target_c = c+1;
		} else {
			target_r = r+1;
			target_c = c-1;
		}
		//cout << "row :" << target_r << "col: " << target_c << endl;
		bool isSuccess;
		try{
		   isSuccess = 
				thePlayer->visit(*board[target_r][target_c], type); //catch throw
		}
		catch (VisitExcept& exc) {
			//cout << "here!!!!!" << endl;
			isSuccess = true;
			if (exc.state == "stair"){
				clearFloor(false);
				init();
				// reduce the gabage
			} else if (exc.state == "pickup_potion"){
					board[target_r][target_c] = make_shared<Tile>(target_c,target_r);
					//aaron have to return visitExcept with "string"
					//throw;		
			//	theDisplay.w->notify(*board[target_r][target_c]);
			} else if (exc.state == "pickup_gold"){
					board[target_r][target_c] = make_shared<Tile>(target_c,target_r);
			} else {
			// enemy is dead {
			     //delete enemy
			     auto deadEnemy = find(theEnemy.begin(),theEnemy.end(),board[target_r][target_c]);
			     theEnemy.erase(deadEnemy);
				if (exc.state == "small_hoard") {
					board[target_r][target_c] = make_shared<Small_Hoard>(target_c, target_r);
				} else if (exc.state == "normal_hoard"){
					while (exc.num > 1) {
					board[target_r][target_c] = make_shared<Normal_Hoard>(target_c, target_r);
					int randr, randc;
					do {
						randr = getRandom (-1, 1) + target_r;
						if (randr == 0) {
							randc = getRandom (0, 1) * 2 -1 + target_c;
						} else randc = getRandom (-1, 1) + target_c;
					} while (!board[target_r][target_c]->visit(*board[randr][randc], MOVE));
						swap(board[randr][randc]->getPos().posx, board[target_r][target_c]->getPos().posx);
						swap(board[randr][randc]->getPos().posy, board[target_r][target_c]->getPos().posy);
						swap(board[randr][randc], board[target_r][target_c]);
						theDisplay.w->notify(*board[randr][randc]);
						--exc.num;
					}
						board[target_r][target_c] = make_shared<Normal_Hoard>(target_c, target_r);
						
				} else {// merchant_hoard


//merchant dragon drop 
				}
			}
		}
		if (!isSuccess) {
				//cout << "false" << endl;
		} else {
			if (type == MOVE){
				//cout << "true" << endl;
				thePlayer->getPos().posx = target_c;
				thePlayer->getPos().posy = target_r;
			//	theDisplay.w->notify(*thePlayer);
			//	theDisplay.p->notify(*thePlayer);
				//	cout << *this;
			} else if (type == ATTACK) {
				theDisplay.p->notify(*thePlayer);
			} else {
				//cout << "PICKUP condition" << endl;
			}
		}
		theDisplay.w->notify(*thePlayer);
		theDisplay.w->notify(*board[target_r][target_c]);
		theDisplay.p->notify(*thePlayer);

		sort(theEnemy.begin(), theEnemy.end(), compare);
		if (!stop) {
			for (int i = 0; i < theEnemy.size(); i++) {
				int r = theEnemy[i]->getPos().posy;
				int c = theEnemy[i]->getPos().posx;
				int player_r = thePlayer->getPos().posy;
				int player_c = thePlayer->getPos().posx;
				bool playeraround = false;
				if (abs(player_r - r) <= 1 && abs(player_c - c) <= 1){
					try	{
					//cout << "player is attacked" << endl;
						if (theEnemy[i]->visit(*thePlayer, ATTACK)) playeraround = true;
					}
					catch(VisitExcept & exc){
						if (exc.state == "deadplayer"){
						//cout << "player is dead!!!!!!!!!!!!!!" << endl;
							playeraround = true;
							throw true;
						}
					}
				}
				if (!playeraround){
					vector<bool> possibility(8,false);
					if (enemyMove(i, possibility)){
				
					} else {
						//cout << "enemy move false" << endl;
					}
				} else {
					theDisplay.p->notify(*thePlayer);
				}
			}
		}
		thePlayer->getPlayerInfo().action = "";
	}


void T_Floor::pause(){
	if (stop) stop = true;
	else stop = false;
}

bool T_Floor::enemyMove(int n, vector<bool>& possibility) {
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
}

ostream &operator<<(ostream &out, const T_Floor &f){
	out << *f.theDisplay.w; //this is window.
	out << *f.theDisplay.p; //this is plane.
	return out;
}

