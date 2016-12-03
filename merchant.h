#ifndef MERCHANT_H
#define MERCHANT_H
#include"enemy.h"
#include "style.h"
#include "type.h"
class Object;
class Shade;

class Merchant: public Enemy{
	public:
  	Merchant (int row, int col);
    bool visit (Object &object, Type type);
/*j	bool visit_object(Type t);
	bool visit(Object&, Type t);
	//be_visit
	bool be_visit(Shade& , Type t);
	bool be_visit(Drow& , Type t);
	bool be_visit(Vampire& , Type t);
	bool be_visit(Troll& , Type t);
	bool be_visit(Goblin& , Type t);
	*/
};

#endif
