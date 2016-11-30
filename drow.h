#ifndef __DROW_H_
#define __DROW_H_
#include "player.h"
#include "type.h"

class Drow: public Player{
  public: 
   	Drow(int row, int col);
    bool visit(Object&, Type t);

/*	bool be_visit(Restore_Health& , Type t) override;
	bool be_visit(Boost_Atk& , Type t) override;
	bool be_visit(Boost_Def& , Type t) override;
	bool be_visit(Poison_Health& , Type t) override;
	bool be_visit(Wound_Atk& , Type t) override;
	bool be_visit(Wound_Def& , Type t) override;
	*/

};

#endif
