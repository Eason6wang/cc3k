#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include "type.h"
#include "style.h"

class Enemy: public Character{
  public:
    Enemy(int hp, int atk, int def, int row, int col, Style style);
    ~Enemy() = default;
//	virtual bool visit(Object &object, Type type) override;
	//virtual bool be_visit(Shade&shade, Type t) ;
//	virtual bool be_visit(Vampire& , Type t) override;
//	virtual bool be_visit(Troll& , Type t) override;
//	virtual bool be_visit(Goblin& , Type t) override;



};

#endif
