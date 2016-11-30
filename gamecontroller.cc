#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "gamecontroller.h"
#include "quit.h"
#include "window.h"
using namespace std;

//Game::GameController(){}

void GameController::play(string file){
	srand(time(NULL));
	//dlc
	//string bonus;
	//cin >> bonus;
	//switch 
	cout << "enter the play()" << endl;
	Window theWindow {"welcome.txt"};
	cout << theWindow;
	floor.init(file);
/*	floor.setPlayer();
	floor.setStair();
	for (int i = 0; i < 10; i++){
//		f.setPotion();
		floor.setTreasure();
	}
    
	for (int j = 0; j < 20; j++){
		floor.setEnemy();
	}*/
    cout << floor; //use display.

	//the floor is generated 	
	string cmd;
	while (true) {
		try {
			cin >> cmd;
			string direction;
		   	if (cmd == "u") {
                cin >> direction;
				floor.floorVisit(direction, PICKUP);
			} else if (cmd == "a") {
                cin >> direction;
				floor.floorVisit(direction, ATTACK);
			} else if (cmd == "f") {
				floor.pause();
			} else if (cmd == "r") {
				floor.init(file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw Quit{};
			} else {
                cin >> direction;
				floor.floorVisit(direction, MOVE);
			}
		}
		catch (Quit& q) {
            cout << "quit" << endl;
        }
    }
}
				

