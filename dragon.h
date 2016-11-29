#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include "type.h"
#include "style.h"
#include<string>

class Object;
class Shade;

class Dragon: public Enemy{
    std::string race = "D";
public:
    Dragon(int, int);
	bool visit(Object&, Type t) override;
	//be_visit
	bool be_visit(Shade& , Type t)override;
//	bool be_visit(Drow& , Type t)override;
//	bool be_visit(Vampire& , Type t)override;
//	bool be_visit(Troll& , Type t)override;
//	bool be_visit(Goblin& , Type t)override;
//        bool be_visit(Human& , Type t) override;
//	bool be_visit(Dwarf& , Type t) override;
//	bool be_visit(Halfling& , Type t) override;
//	bool be_visit(Elf& , Type t) override;
//	bool be_visit(Orc& , Type t) override;
//	bool be_visit(Dragon& , Type t) override;
//	bool be_visit(Merchant& , Type t) override;

};

#endif
