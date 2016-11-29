#ifndef __GOBLIN_H_
#define __GOBLIN_H_

class Goblin: public Player{
  public:
  	Goblin(int, int, int); 
  	bool visit(Object&, Type t);
	bool be_visit(Orc & enemy, Type t);
};

#endif
