#ifndef __PLAYER_H_
#define __PLAYER_H_
#include<string>
#include "character.h"
#include "playerinfo.h"
#include "type.h"
#include "style.h"


class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
/*class Dragon;
class Merchant;
class Small_Hoard;
class Normal_Hoard;
class Dragon_Hoard;
class Merchant_Hoard;
class Restore_Health;
class Boost_Atk;
class Boost_Def;
class Poison_Health;
class Wound_Atk;
class Wound_Def;
*/

class Player: public Character{
  	PlayerInfo playerInfo;
	bool visible = true;
  public: 
	virtual Info& getInfo () override;
    PlayerInfo& getPlayerInfo();
    Player(int hp, int atk, int def, int row, int col, Style style);
    //Player(Player &);
    virtual bool isvisible();
    void levelUp();
    virtual ~Player() = default;

	virtual bool be_visit(Human& , Type t) override;
	virtual bool be_visit(Dwarf& , Type t) override;
	virtual bool be_visit(Halfling& , Type t) override;
	virtual bool be_visit(Elf& , Type t) override;
	virtual bool be_visit(Orc& , Type t) override;
	virtual bool be_visit(Dragon& , Type t) override;
	virtual bool be_visit(Merchant& , Type t) override;
	virtual bool be_visit(BloodElf& , Type t) override;
	virtual bool be_visit(ForSaken& , Type t) override;
	virtual bool be_visit(Worgen& , Type t) override;

};

#endif
