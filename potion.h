#ifndef __POTION_H__
#define	__POTION_H__
#include "item.h"
class Player;
class Info;

class Potion :public Item {
	protected:
	std::shared_ptr<Potion> potion;
	public:
	virtual Info modify () = 0;
	Potion (int row, int col, Style style, std::shared_ptr<Potion> potion);
	virtual ~Potion () = default;
};

#endif




