#ifndef __DWARF_H_
#define __DWARF_H_
#include"enemy.h"
#include "style.h"
#include "type.h"
#include<string>

class Object;

class Dwarf: public Enemy{
  std::string race = "D";
  public: 
  	Dwarf(int, int);
   	bool visit(Object&, Type t);
};


#endif
