#include <iostream>
#include <curses.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "gamecontroller.h"
#include "quit.h"
#include "window.h"
#include "panel.h"
using namespace std;

GameController::GameController():display{make_shared<Window>("welcome.txt"), make_shared<Panel>(nullptr)}, floor{display}{
	display.display(display.w);
}

void GameController::startGame(string file){
	char option;
	cin >> option;
	if (option == 'c') {
		play(file);
	} else if (option == 'e'){
		wasdPlay(file);
	}
}

void GameController::play(string file){
	srand(time(NULL));
	//dlc
	//string bonus;
	//cin >> bonus;
	//switch 
	cout << "enter the play()" << endl;
	//Window theWindow {"welcome.txt"};
	//cout << theWindow;
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
    display.display();//cout << floor; //use display.

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
				floor.clearFloor();
				floor.init(file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw Quit{};
			} else {
				cout << "move !!!!" << endl;
				floor.floorVisit(cmd, MOVE);
			}
		}
		catch (Quit& q) {
            cout << "quit" << endl;
        }
    }
}
				
void GameController::wasdPlay(string file){
	srand(time(NULL));
	initscr();
	//Window theWindow {"welcome.txt"};
	//addstr(theWindow.outPut().c_str());
	floor.init(file);
    addstr(floor.outPut().c_str());//use display.

	//the floor is generated 	
	char key;
	while (true) {
		try {
			key = getch();
			char direction;
		   	if (key == 'U' || key == 'u') {
                direction = getch();
				switch (direction){
					case 'w':
					case 'W':
						floor.floorVisit("no", PICKUP);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", PICKUP);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", PICKUP);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", PICKUP);
						break;
				}
			} else if (key == 'A' || key == 'a') {
			  	direction = getch();
				switch (direction){
					case 'w':
					case 'W':
						floor.floorVisit("no", ATTACK);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", ATTACK);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", ATTACK);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", ATTACK);
						break;
				}
			} else if (key == 'f' || key == 'F') {
				floor.pause();
			} else if (key == 'r' || key == 'R') {
				floor.init(file); //remember to generate enemies again
			} else if (key == 'q' || key == 'Q') {
				throw Quit{};
			} else {
				switch (key){
					case 'w':
					case 'W':
						floor.floorVisit("no", MOVE);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", MOVE);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", MOVE);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", MOVE);
						break;
				}
			}
		}
		catch (Quit& q) {
        cout << "quit" << endl;
		}
		refresh();
	}
}

