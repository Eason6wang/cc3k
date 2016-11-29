#include "floor.h"
#include "type.h"
using namespace std;

int Floor::getRandom(int min, int max){
	srand(time(NULL));
	int n = max - min + 1;
	int rn = rand() % n + min;
	return rn;
}


Floor::void clearFloor(){
	if (w != nullptr) {
		thePlayer.levelUp(); //player add a method levelUp.
		w.reset(nullptr);
		p.reset(nullptr);
		board.clear();
	}
}
	

Floor::Floor(): height{25}, width{79}, stop{false} {}
	

//Floor::~Floor() {} //smart pointer will delete. so try use default.

void Floor::init(string file){ // set up the board according to the given floor in the file.
	clearFloor();
	height = 25;
	width = 79;
	w = make_shared<Window>(file);
	p = make_shared();
	ifstream f {file};
	string line;
	for (int r = 0; r < width; r++){
		vector<shared_ptr<Object>> arr;
		getline(f, line);
		for (int c = 0;c < width; c++){
			if (line[c] == '.') {
				auto o = make_shared<Tiles>();
			} else if (line[c] == '-') {
				auto o = make_shared<Horizontal_Wall>();
			} else if (line[c] == '|') {
				auto o = make_shared<Vertical_Wall>();
			} else if (line[c] == '+') {
				auto o = make_shared<Door>();
			} else if (line[c] == '#') {
				auto o = make_shared<Passage>();
			} else {
				auto o = make_shared<Space>();
			}
			//add more conditions to achieve read another type of floor (all set).
			o->setCoordinate();
			o->attach(w);
			arr.emplace_back(o);
		}
		board.emplace_back(arr);
	}
	//board = vector<vector<Object*>> (height, vector<Object*> (width));
	//for (int i = 0; i < height; i++) {
	//	for (int j = 0; j < width; i++){
	//		if (i - 1 >= 0) {
	//			board[i][j].attach(board[i-1][j]);
	//			if (j -1 >= 0){
	//				board[i][j].attach(board[i-1][j-1]);
	//			}
	//		    if (j +1 < width){
	//			    board[i][j].attach(board[i-1][j+1]);
	//			}
	//		}
	//		if (i + 1 < height){
	//			board[i][j].attach(board[i+1][j]);
	/*			if (j - 1 >= 0){
					board[i][j].attach(board[i+1][j-1]);
				}
				if (j + 1 < width) {
					board[i][j].attach(board[i+1][j+1]);
				}
			}
			if (j - 1 >= 0) {
				board[i][j].attach(board[i][j-1]);
			}
			if (j + 1 < width) {
				board[i][j].attach(board[i][j+1]);
			}
			board[i][j].attach(w); //attach window to each object.
		}
	}*/
	//detect chamber;
	for (int t = 0, t < 5; t++) {
		int row,col;
		do {
			row = getRandom(0, height);
			col = getRandom(0, width);
		} while (board[row][col]->getPos().style != Tile);
		Chamber cham;
		setChamber(row, col, cham.c);
		theChamber.emplace_back(cham);
	}
}

void Floor::setChamber(int r, int c, vector<shared_ptr<Object*>> arr) {
	if (board[r-1][c]->getPos().style == Tile) {
		arr.emplace_back(board[r-1][c]);
		setChamber(r-1, c, auto arr);
	}
	if (board[r+1][c]->getPos().style == Tile) {
		arr.emplace_back(board[r+1][c]);
		setChamber(r+1,c, auto arr);
	}
	if (board[r][c-1]->getPos().style == Tile) {
		arr.emplace_back(board[r][c-1]);
		setChamber(r,c-1, auto arr);
	}
	if (board[r][c+1]->getPos().style == Tile) {
		arr.emplace_back(board[r][c+1]);
		setChamber(r,c+1, auto arr);
	}
	arr.emplace_back(board[r][c]);
}
	

void Floor::setPlayer(shared_ptr<Player> p){ // generate player.
	//selectplayer.
	while (true){
	 //put this part in to display later.
		wcout << "Choose your player: (s, d, v, g, t)" << endl;
		char player;
		cin >> player;
		if (player == 's'){
			thePlayer = make_shared<Shade>(); //the hp atk .. is assigned in ctor.
		} else if (player == 'd') {
			thePlayer = make_shared<Drow>();
		} else if (player == 'v') {
			thePlayer = make_shared<Vampire>();
		} else if (player == 'g') {
			thePlayer = make_shared<Goblin>();
		} else if (player == 't') {
			thePlayer = make_shared<Troll>();
		} else {
			thePlayer = make_shared<Shade>();
			continue;}
		break;
	}
	int n = getRandom(0,4);
	int pos = getRandom(0,theChamber[n].c.size() - 1);
	this->p = make_shared<Panel>(); //create a panel here
	p.attach(this->p); //attach panel to each player.
	int position = theChamber[n].c[pos]->getPos();
	p->setCoordinate(position.posy, position.posx);
	thePlayer =  p;
	theChamber[n].c.erase(begin() + pos);
}

void Floor::setStairWay(){ //generate stairway.
	int n = getRandom(0,4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	auto o = make_shared<Stair>();
	int position = theChamber[n].c[pos]->getPos();
	o->setCoordinate(position.posy, position.posx);
	theStair = o;	
	theChamber[n].c.erase(begin() + pos);
}

void Floor::setPotion(){ //generate potion
	int n = getRandom(0, 4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	int p = getRandom(1,6);
	auto o;
	switch (p){
		case 1: 
			o = make_shared<Restore_Health>(); //ctor should take in x y to set position.
			break;
		case 2:
			o = make_shared<Boost_Atk>();
			break;
		case 3:
			o = make_shared<Boost_Def>();
			break;
		case 4: 
			o = make_shared<Poison_Health>();
			break;
		case 5:
			o = make_shared<Wound_Atk>();
			break;
		case 6:
			o = make_shared<Wound_Def>();
			break;
	}
	int position = theChamber[n].c[pos]->getPos();
	o->setCoordinate(position.posy, position.posx);
	thePotion.emplace_back(o);
	theChamber[n].c.erase(begin() + pos);
}

void Floor::setTreasure(){ //generate gold.
	int n = getRandom(0, 4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	int p = getRandom(1,8);
	auto o;
	switch (p){
		case 1: 
		case 2:
		case 3:
		case 4: 
		case 5:
			o = make_shared<Normal>();
			break;
		case 6:
        case 7: 
			o = make_shared<Small_Hoard>();
			break;
		case 8:
			o = make_shared<Dragon_Hoard>(); //I expect the ctor of DH spawn a dragon here!!!!
			break;
	}
	int position = theChamber[n].c[pos]->getPos();
	o->setCoordinate(position.posy, position.posx);
	theTreasure.emplace_back(o);
	theChamber[n].c.erase(begin() + pos);
}


void Floor::setEnemy(){ //generate enemy.
	int n = getRandom(0, 4);
	int pos = getRandom(0, theChamber[n].c.size() - 1);
	int p = getRandom(1,18);
	auto o;
	switch (p){
		case 1: 
		case 2:
		case 3:
		case 4: 
			o = make_shared<Human>();
			break;
		case 5:
		case 6:
		case 7: 
			o = make_shared<Dwarf>();
			break;
		case 8:
		case 9:
		case 10: 
		case 11:
		case 12:
			o = make_shared<Halfling>();
			break;
		case 13: 
		case 14:
			o = make_shared<Elf>();
			break;
		case 15:
		case 16: 
			o = make_shared<Orc>();
			break;
		case 17:
		case 18:
			o = make_shared<Merchant>();
			break;
	}
	int position = theChamber[n].c[pos]->getPos();
	o->setCoordinate(position.posy, position.posx);
	theEnemy.emplace_back(o);
	theChamber[n].c.erase(begin() + pos);
}

void Floor::floorVisit(string s, Type type){
	int r = thePlayer->getPos().posy;
	int c = thePlayer->getPos().posx;
	int target_r, target_c;
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
	thePlayer->visit(board[target_r][target_c], type);
	//enemy random move.
	if (!stop) {
		for (int i = 0; i < theEnemy.size(); i++) {
			enemyMove(i);
		}
	}
}

void Floor::stop(){
	if (stop) stop = true;
	else stop = false;
}

void Floor::enemyMove(int n) {
	int r = thePlayer->getPos().posy;
	int c = thePlayer->getPos().posx;
	int target_r, target_c;
	int i = getRandom(1,8);
	if (i == 1) {
		target_r = r-1;
		target_c = c;
	} else if (i == 2) {
		target_r = r+1;
		target_c = c;
	} else if (i == 3) {
		target_r = r;
		target_c = c+1;
	} else if (i == 4) {
		target_r = r;
		target_c = c-1;
	} else if (i == 5){
		target_r = r-1;
		target_c = c+1;
	} else if (i == 6){
		target_r = r-1;
		target_c = c-1;
	} else if (i == 7){
		target_r = r+1;
		target_c = c+1;
	} else {
		target_r = r+1;
		target_c = c-1;
	}
	theEnemy[n]->visit(board[target_r][target_c], MOVE);
}

ostream &operator<<(std::ostream &out, const Floor &f){
	out << w << endl; //this is window.
	out << p << endl; //this is plane.
	return out;
}







