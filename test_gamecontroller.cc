#include <iostream>
#include "buff.h"
#include <sstream>
#include <curses.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "test_gamecontroller.h"
#include "quit.h"
#include "window.h"
#include "panel.h"
using namespace std;

T_GameController::T_GameController():t_floor{display}{}
//	display.display(display.w);


void T_GameController::play(string file){
	srand(time(NULL));
	cout << "enter the play()" << endl;
	t_floor.initHelper(file);	
	t_floor.init("level1.txt");
	display.display();
	string cmd;
	while (true) {
		try {
			cin >> cmd;
			string direction;
		   	if (cmd == "u") {
                cin >> direction;
				t_floor.floorVisit(direction, PICKUP);
			} else if (cmd == "a") {
                cin >> direction;
				t_floor.floorVisit(direction, ATTACK);
			} else if (cmd == "f") {
				t_floor.pause();
			} else if (cmd == "r") {
				t_floor.clearFloor(true);
				t_floor.init(file); //remember to generate enemies again
			} else if (cmd == "q") {
				throw false;
			} else {
				cout << "move !!!!" << endl;
				t_floor.floorVisit(cmd, MOVE);
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
				

