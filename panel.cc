#include "panel.h"
#include <sstream>
using namespace std;
//Panel::Panel();
	
	
void Panel::notify(Subject &whoNotify) {
	gold = p->getPlayerInfo().gold;
	floor = p->getPlayerInfo().level;
	hp = p->getInfo().hp;
	atk = p->getInfo().atk;
	def = p->getInfo().def;
	string action = p->getPlayerInfo().action;
}
	
//Panel::~Panel();


ostream &operator<<(std::ostream &out, const Panel &p){
	ostringstream ss;
	for (int i = 0; i < 63; i++){
		ss << " ";
	}
	string s = ss.str();
	ostringstream ss1;
	ss1 << "Race : " << p.race << " Gold: " << p.gold;
	string s1 = ss1.str();
	string s2 = s1 + s;
	int pos = 70;
	s2[pos] = 'F';
	s2[pos+1] = 'l';
	s2[pos+2] = 'o';
	s2[pos+3] = 'o';
	s2[pos+4] = 'r';
	ostringstream ss3;
    ostringstream ss2;
	ss2 << p.floor;
	string s3 = ss3.str();
	int n = s3.length();
	for (int j = 0; j < n; j ++){
		s2[pos+5+j] = s3[j];
	}
	out << s2 << endl;
	out << "HP: " << p.hp << endl;
	out << "Atk: " << p.atk << endl;
	out << "Def: " << p.def << endl;
	out << "Action: " << p.action << endl;
	return out;
}
