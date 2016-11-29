#ifndef __VAMPIRE_H_
#define __VAMPIRE_H_

class Vampire: public Player{
  public:
  	Vampire(int, int, int); 
   	bool visit(Object&, Type t);

};

#endif
