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


void colorWindow(vector<vector<char>> window) {
	start_color();
	int OFF_WHITE = 10;
	int SLATE_GRAY = 11;
	int DARK_GREEN = 12;
	int SIENNA = 13;
	int HONEYDEW = 14;
	int GRAY = 15;
	int ORANGE = 16;
	int SLATE_BLUE = 17;
	init_color(OFF_WHITE, 804,686,584);
	init_color(SLATE_GRAY,193,310,310);
	init_color(COLOR_YELLOW,700,700,0);
	init_color(DARK_GREEN,0,392,0);
	init_color(SIENNA,628,322,176);
	init_color(HONEYDEW,0,1000,498);
	init_color(GRAY,700,700,700);
	init_color(ORANGE,1000,647,0);
	init_color(SLATE_BLUE,518,439,1000);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, SLATE_GRAY, COLOR_BLACK);
	init_pair(8, OFF_WHITE, COLOR_BLACK);
	init_pair(9, DARK_GREEN, COLOR_BLACK);
	init_pair(10, SIENNA, COLOR_BLACK);
	init_pair(11, HONEYDEW, COLOR_BLACK);
	init_pair(12, GRAY, COLOR_BLACK);
	init_pair(13, ORANGE, COLOR_BLACK);
	init_pair(14, SLATE_BLUE, COLOR_BLACK);
	
	vector<pair<int,int>> player = findChar(window,'@');
	vector<pair<int,int>> merchant = findChar(window,'M');
	vector<pair<int,int>> gold = findChar(window, 'G');
	vector<pair<int,int>> potion = findChar(window, 'P');
	vector<pair<int,int>> stair = findChar(window, '\\');
	vector<pair<int,int>> passage = findChar(window, '#');
	vector<pair<int,int>> door = findChar(window, '+');
	vector<pair<int,int>> v_wall = findChar(window, '|');
	vector<pair<int,int>> h_wall = findChar(window, '-');
	vector<pair<int,int>> human  = findChar(window, 'H');
	vector<pair<int,int>> halfling = findChar(window, 'L');
	vector<pair<int,int>> elf = findChar(window, 'E');
	vector<pair<int,int>> dwarf = findChar(window, 'W');
	vector<pair<int,int>> dragon = findChar(window,'D');
	vector<pair<int,int>> tile = findChar(window,'.');

//	mvaddstr(0,0, s.c_str());
	attron(COLOR_PAIR(12));
	colorLayer(tile, '.');
	attroff(COLOR_PAIR(12));

	attron(COLOR_PAIR(13));
	colorLayer(dragon, 'D');
	attroff(COLOR_PAIR(13));

	attron(COLOR_PAIR(14));
	colorLayer(dwarf, 'W');
	attroff(COLOR_PAIR(14));
	
	attron(COLOR_PAIR(9));
	colorLayer(halfling, 'L');
	attroff(COLOR_PAIR(9));
	
	attron(COLOR_PAIR(10));
	colorLayer(human, 'H');
	attroff(COLOR_PAIR(10));

	attron(COLOR_PAIR(11));
	colorLayer(elf, 'E');
	attroff(COLOR_PAIR(11));
	
	attron(COLOR_PAIR(6));
	colorLayer(merchant, 'M');
	attroff(COLOR_PAIR(4));


	attron(COLOR_PAIR(7));
	colorLayer(passage, '#');
	attroff(COLOR_PAIR(7));
	
	attron(COLOR_PAIR(8));
	colorLayer(v_wall, '|');
	colorLayer(h_wall, '-');
	attroff(COLOR_PAIR(8));

	attron(COLOR_PAIR(4));
	colorLayer(potion, 'p');
	attroff(COLOR_PAIR(4));
	
	attron(COLOR_PAIR(6));
	colorLayer(merchant, 'M');
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(2));
	colorLayer(door, '+');
	attroff(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(3));
	colorLayer(stair, '\\');
	attroff(COLOR_PAIR(3));
	
	attron(COLOR_PAIR(1));
	colorLayer(player, '@');
	attroff(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(5));
	colorLayer(gold, 'G');
	attroff(COLOR_PAIR(5));
}	

D_GameController::D_GameController():d_floor{display}{}
//	display.display(display.w);


void D_GameController::play(string file){
	srand(time(NULL));
	initscr();
	start_color();
	shared_ptr<Window> theWindow = make_shared<Window>("dlc_version.txt");
	mvaddstr(0,0,theWindow->outPut().c_str());//use display.
	d_floor.init(true,file);
    mvaddstr(0,0,d_floor.outPut().c_str());//use display.
	colorWindow(display.w->colorOutPut());
	move(31,0);
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
			colorWindow(display.w->colorOutPut());
			move(31, 0);
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
