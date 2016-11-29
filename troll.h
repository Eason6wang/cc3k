#ifndef __TROLL_H_
#define __TROLL_H_

class Troll: public Player{
  public:
  	Troll(int, int, int); 
     	bool visit(Object&, Type t);

};

#endif
