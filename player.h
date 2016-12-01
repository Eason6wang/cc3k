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
  public: 
	Info& getInfo () override;
    PlayerInfo& getPlayerInfo();
    Player(int hp, int atk, int def, int row, int col, Style style);
    //Player(Player &);
    void levelUp();
    virtual ~Player() = default;

	virtual bool be_visit(Human& , Type t) override;
	virtual bool be_visit(Dwarf& , Type t) override;
	virtual bool be_visit(Halfling& , Type t) override;
	virtual bool be_visit(Elf& , Type t) override;
	virtual bool be_visit(Orc& , Type t) override;
/*	virtual bool be_visit(Dragon& , Type t) override;
	virtual bool be_visit(Merchant& , Type t) override;
	virtual bool be_visit(Small_Hoard& , Type t) override;
	virtual bool be_visit(Normal_Hoard& , Type t) override;
	virtual bool be_visit(Merchant_Hoard& , Type t) override;
	virtual bool be_visit(Dragon_Hoard& , Type t) override;
	virtual bool be_visit(Restore_Health& , Type t) override;
	virtual bool be_visit(Boost_Atk& , Type t) override;
	virtual bool be_visit(Boost_Def& , Type t) override;
	virtual bool be_visit(Poison_Health& , Type t) override;
	virtual bool be_visit(Wound_Atk& , Type t) override;
	virtual bool be_visit(Wound_Def& , Type t) override;
*/
};

#endif
