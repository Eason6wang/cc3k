#include <iostream>
#include <sstream>
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
	
	floor.init(false, file);
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
				floor.floorVisit(direction, PICKUP, false);
			} else if (cmd == "a") {
                cin >> direction;
				floor.floorVisit(direction, ATTACK, false);
			} else if (cmd == "f") {
				floor.pause();
			} else if (cmd == "r") {
				floor.clearFloor(true);
				floor.init(false,file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw false;
			} else {
				cout << "move !!!!" << endl;
				floor.floorVisit(cmd, MOVE, false);
			}
			display.display();
		}
		catch (bool restart) {
			if (restart) {
				shared_ptr<Window> endWindow = make_shared<Window>("endwindow.txt");
				display.display(endWindow);
			} else {
				throw;
			}
        }
    }
}
				
void GameController::wasdPlay(string file){
	srand(time(NULL));
	initscr();
	//Window theWindow {"welcome.txt"};
	//addstr(theWindow.outPut().c_str());
	floor.init(true,file);
	//string themap = floor.outPut();
    mvaddstr(0,0,floor.outPut().c_str());//use display.
//    mvaddstr(0,0,themap.c_str());//use display.
    //mvaddstr(10,0,display.w->outPut().c_str());//use display.
   // mvaddstr(10,0,display.p->outPut().c_str());//use display.

	//the floor is generated 	
	char key;
	while (true) {
		try {
			key = getch();
			char direction;
		   	if (key == 'K' || key == 'k') {
                direction = getch();
				switch (direction){
					case 'w':
					case 'W':
						floor.floorVisit("no", PICKUP, true);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", PICKUP, true);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", PICKUP, true);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", PICKUP, true);
						break;
				}
			} else if (key == 'J' || key == 'j') {
			  	direction = getch();
				switch (direction){
					case 'w':
					case 'W':
						floor.floorVisit("no", ATTACK, true);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", ATTACK, true);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", ATTACK, true);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", ATTACK, true);
						break;
				}
			} else if (key == 'f' || key == 'F') {
				floor.pause();
			} else if (key == 'r' || key == 'R') {
				floor.clearFloor(true);
				floor.init(true, file); //remember to generate enemies again
			} else if (key == 'q' || key == 'Q') {
				throw false;
			} else {
				switch (key){
					case 'w':
					case 'W':
						floor.floorVisit("no", MOVE, true);
						break;
					case 's':
					case 'S':
						floor.floorVisit("so", MOVE, true);
						break;
					case 'a':
					case 'A':
						floor.floorVisit("we", MOVE, true);
						break;
					case 'd':
					case 'D':
						floor.floorVisit("ea", MOVE, true);
						break;
				}
			}
		}
		//	mvaddstr(0,0,floor.outPut().c_str());//use display.
		//	refresh();
		catch (bool restart) {
			if (restart) {
				shared_ptr<Window> endWindow = make_shared<Window>("endwindow.txt");
				mvaddstr(0,0,(display.w)->outPut().c_str());//use display.
			} else {
				throw;
			}
		}
		mvaddstr(0,0,floor.outPut().c_str());//use display.
		refresh();		
	}
}

