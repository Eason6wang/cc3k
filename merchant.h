#ifndef MERCHANT_H
#define MERCHANT_H
#include"enemy.h"
#include "style.h"
#include "type.h"
class Object;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;


class Merchant: public Enemy{
    bool revenge = false;
	public:
  	Merchant (int row, int col);
        bool visit (Object &object, Type type);
	bool be_visit(Shade& , Type t);
	bool be_visit(Drow& , Type t);
	bool be_visit(Vampire& , Type t);
	bool be_visit(Troll& , Type t);
	bool be_visit(Goblin& , Type t);
	
};

#endif
