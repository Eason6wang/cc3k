#ifndef __ORC_H_
#define __ORC_H_
#include"enemy.h"
#include "style.h"
#include "type.h"
#include<string>

class Object;

class Orc: public Enemy{
  std::string race = "O";
  public: 
  	Orc(int, int);
   	bool visit(Object&, Type t);
};

#endif
