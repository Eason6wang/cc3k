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
	Potion (int posx, int posy, Style style, std::shared_ptr<Potion> potion);
	virtual ~Potion () = default;
	bool be_visit (Player &player, Type type) override;
};

#endif




