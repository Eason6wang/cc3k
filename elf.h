#ifndef __ELF_H_
#define __ELF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"

class Object;

class Elf: public Enemy{
  public: 
  	Elf (int row, int col);
    bool visit (Object &object, Type type);
	bool be_visit (Shade &shade, Type type);
   	/*bool visit(Object&, Type t);
	bool be_visit(Shade& , Type t) override;
	bool be_visit(Vampire& , Type t) override;
	bool be_visit(Troll& , Type t) override;
	bool be_visit(Goblin& , Type t) override;
	*/

};

#endif
