#ifndef __HALFLING_H_
#define __HALFLING_H_
#include"enemy.h"
#include "style.h"
#include "type.h"
#include<string>

class Object;

class Halfling: public Enemy{
  std::string race = "L";
  public: 
  	Halfling(int, int);
   	bool visit(Object&, Type t);
};


#endif
