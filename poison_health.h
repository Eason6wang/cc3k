#ifndef __POISON_HEALTH_H__
#define __POISON_HEALTH_H__
#include "potion.h"
#include "info.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Poison_Health final:public Potion {
	public:
	Info modify () override;
	Poison_Health (int posx, int posy);
	bool be_visit(Shade& , Type t) override;
	bool be_visit(Drow & , Type t) override;
	bool be_visit(Vampire& , Type t) override;
	bool be_visit(Goblin& , Type t) override;
	bool be_visit(Troll& , Type t) override;
};

#endif


