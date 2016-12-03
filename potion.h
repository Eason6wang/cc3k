#ifndef __POTION_H__
#define	__POTION_H__
#include "item.h"
#include "info.h"


class Shade;
class Vampire;
class Drow;
class Troll;
class Goblin;
class Player;

class Potion :public Item {
	protected:
	Info info;
	std::shared_ptr<Potion> potion;
	public:
	Info &modify ();
	std::shared_ptr<Potion> & getPotion();
	Potion (int row, int col, Style style);
	virtual bool be_visit(Shade &player, Type type);
	virtual bool be_visit(Vampire&player, Type type);
	virtual bool be_visit(Drow&player, Type type);
	virtual bool be_visit(Troll&player, Type type);
	virtual bool be_visit(Goblin &player, Type type);
	virtual ~Potion () = default;
};

#endif




