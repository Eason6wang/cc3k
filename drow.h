#ifndef __DROW_H_
#define __DROW_H_

class Drow: public Player{
  public: 
   	Drow(int, int, int);
        bool visit(Object&, Type t);

	bool be_visit(Restore_Health& , Type t) override;
	bool be_visit(Boost_Atk& , Type t) override;
	bool be_visit(Boost_Def& , Type t) override;
	bool be_visit(Poison_Health& , Type t) override;
	bool be_visit(Wound_Atk& , Type t) override;
	bool be_visit(Wound_Def& , Type t) override;

};

#endif
