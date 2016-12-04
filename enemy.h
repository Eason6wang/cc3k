#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include "type.h"
#include "style.h"
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Aaron;

class Enemy: public Character{
  public:
    Enemy(int hp, int atk, int def, int row, int col, Style style);
    ~Enemy() = default;
	virtual bool be_visit (Shade &shade, Type type) override;
	virtual bool be_visit (Aaron&shade, Type type) override;
	virtual bool be_visit(Drow &drow, Type t) override;
	virtual bool be_visit(Vampire &vampire, Type t) override;
	virtual bool be_visit(Troll &troll, Type t) override;
	virtual bool be_visit(Goblin &goblin, Type t) override;
};

#endif
