#include <iostream>
#include "buff.h"
#include <sstream>
#include <curses.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "object.h"
#include "dlc_gamecontroller.h"
#include "quit.h"
#include "window.h"
#include "panel.h"
using namespace std;

D_GameController::D_GameController():d_floor{display}{}
//	display.display(display.w);


void D_GameController::play(string file){
	srand(time(NULL));
	initscr();
	shared_ptr<Window> theWindow = make_shared<Window>("dlc_version.txt");
	mvaddstr(0,0,theWindow->outPut().c_str());//use display.
	d_floor.init(true,file);
    mvaddstr(0,0,d_floor.outPut().c_str());//use display.
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
						d_floor.floorVisit("no", PICKUP, true);
						break;
					case 's':
					case 'S':
						d_floor.floorVisit("so", PICKUP, true);
						break;
					case 'a':
					case 'A':
						d_floor.floorVisit("we", PICKUP, true);
						break;
					case 'd':
					case 'D':
						d_floor.floorVisit("ea", PICKUP, true);
						break;
				}
			} else if (key == 'J' || key == 'j') {
			  	direction = getch();
				switch (direction){
					case 'w':
					case 'W':
						d_floor.floorVisit("no", ATTACK, true);
						break;
					case 's':
					case 'S':
						d_floor.floorVisit("so", ATTACK, true);
						break;
					case 'a':
					case 'A':
						d_floor.floorVisit("we", ATTACK, true);
						break;
					case 'd':
					case 'D':
						d_floor.floorVisit("ea", ATTACK, true);
						break;
				}
			} else if (key == 'f' || key == 'F') {
				d_floor.pause();
			} else if (key == 'r' || key == 'R') {
				d_floor.clearFloor(true);
				d_floor.init(true, file); //remember to generate enemies again
			} else if (key == 'q' || key == 'Q') {
				throw false;
			} else {
				switch (key){
					case 'w':
					case 'W':
						d_floor.floorVisit("no", MOVE, true);
						break;
					case 's':
					case 'S':
						d_floor.floorVisit("so", MOVE, true);
						break;
					case 'a':
					case 'A':
						d_floor.floorVisit("we", MOVE, true);
						break;
					case 'd':
					case 'D':
						d_floor.floorVisit("ea", MOVE, true);
						break;
				}
			}
			clear();
			mvaddstr(0,0,d_floor.outPut().c_str());//use display.
		}
		//	refresh();
		catch (bool restart) {
			if (restart) {
				shared_ptr<Window> endWindow = make_shared<Window>("endwindow.txt");
				clear();
				mvaddstr(0,0,endWindow->outPut().c_str());//use display.
			} else {
				endwin();
				throw;
			}
		}
	//	mvaddstr(0,0,d_floor.outPut().c_str());//use display.
		refresh();		
	}
}

