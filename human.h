#ifndef __HUMAN_H_
#define __HUMAN_H_
#include"enemy.h"
#include "style.h"
#include "type.h"
#include<string>

class Object;

class Human: public Enemy{
 // std::string race = "H";
  public: 
  	Human(int row, int col);
    bool visit (Object &object, Type type);
	bool be_visit (Shade &shade, Type type);
};

#endif
