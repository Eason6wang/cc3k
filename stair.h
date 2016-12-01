#ifndef __STAIR_H__
#define __STAIR_H__
#include "cell.h"
class Character;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
class Dragon;
class Merchant;


class Stair final:public Cell {
	public:
    Stair (int posx, int posy);
        bool be_visit (Shade &player, Type type) override;
/*	bool be_visit (Drow &player, Type type) override;
	bool be_visit (Vampire &player, Type type) override;
	bool be_visit (Troll &player, Type type) override;
	bool be_visit (Goblin &player, Type type) override;
	bool be_visit (Human &enemy, Type type) override;
	bool be_visit (Dwarf &enemy, Type type) override;
	bool be_visit (Halfling &enemy, Type type) override;
	bool be_visit (Elf &enemy, Type type) override;
	bool be_visit (Orc &enemy, Type type) override;
//	bool be_visit (Dragon &enemy, Type type) override;
//	bool be_visit (Merchant &enemy, Type type) override;

*/
};


#endif
