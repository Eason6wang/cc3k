#ifndef __ELF_H_
#define __ELF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"
#include<string>

class Object;

class Elf: public Enemy{
  std::string race = "E";
  public: 
  	Elf(int, int);
   	/*bool visit(Object&, Type t);
	bool be_visit(Shade& , Type t) override;
	bool be_visit(Vampire& , Type t) override;
	bool be_visit(Troll& , Type t) override;
	bool be_visit(Goblin& , Type t) override;
	*/

};

#endif
