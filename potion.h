#ifndef __POTION_H__
#define	__POTION_H__
#include "item.h"


class Shade;
class Vampire;
class Drow;
class Troll;
class Goblin;
class Player;
class Info;

class Potion :public Item {
	protected:
	std::shared_ptr<Potion> potion;
	public:
	virtual Info modify ();
	Potion (int row, int col, Style style, std::shared_ptr<Potion> potion);
	virtual bool be_visit(Shade &player, Type type);
	virtual bool be_visit(Vampire&player, Type type);
	virtual bool be_visit(Drow&player, Type type);
	virtual bool be_visit(Troll&player, Type type);
	virtual bool be_visit(Goblin &player, Type type);
	virtual ~Potion () = default;
};

#endif




