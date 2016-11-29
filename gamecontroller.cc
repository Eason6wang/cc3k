#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "gamecontroller.h"
#include "quit.h"
using namespace std;

//Game::GameController(){}

void GameController::play(string file){
	srand(time(NULL));
	//dlc
	//string bonus;
	//cin >> bonus;
	//switch 
	cout << "enter the play()" << endl;
	f.init(file);
	f.setPlayer();
	f.setStair();
	for (int i = 0; i < 10; i++){
//		f.setPotion();
		f.setTreasure();
	}
    
	for (int j = 0; j < 20; j++){
		f.setEnemy();
	}
    cout << f; //use display.

	//the floor is generated 	
	string cmd;
	while (true) {
		try {
			cin >> cmd;
			string direction;
		   	if (cmd == "u") {
                cin >> direction;
				f.floorVisit(direction, PICKUP);
			} else if (cmd == "a") {
                cin >> direction;
				f.floorVisit(direction, ATTACK);
			} else if (cmd == "f") {
				f.pause();
			} else if (cmd == "r") {
				f.init(file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw Quit{};
			} else {
                cin >> direction;
				f.floorVisit(direction, MOVE);
			}
		}
		catch (Quit& q) {
            cout << "quit" << endl;
        }
    }
}
				

