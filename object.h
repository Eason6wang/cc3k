#ifndef __OBJECT_H_
#define __OBJECT_H_
#include <vector>
#include "subject.h"
#include "observer.h"
#include "pos.h"
#include "type.h"
#include "Headers_Class.h"

class Object: public Subject{
	Pos pos;
public:
	Pos& getPos();
	Object () = default;
	Object (int posx, int posy, Style style);
	void flip ();
	//void set_last (std::shared_ptr<Object> last);

    //virtual Info& getInfo();
	virtual bool visit_objects(Type type);
	virtual bool visit(Object &object, Type type);
	//be_visit
	virtual bool be_visit(Shade& shade, Type type);
	virtual bool be_visit(Drow& drow, Type type);
	virtual bool be_visit(Vampire& vampire, Type type);
	virtual bool be_visit(Troll& typeroll, Type type);
	virtual bool be_visit(Goblin& goblin, Type type);
	virtual bool be_visit(Human& human, Type type);
	virtual bool be_visit(Dwarf& dwarf, Type type);
	virtual bool be_visit(Halfling& halfling, Type type);
	virtual bool be_visit(Elf& elf, Type type);
	virtual bool be_visit(Orc& orc, Type type);
//	virtual bool be_visit(Dragon& dragon, Type type);
	virtual bool be_visit(Merchant& merchant, Type type);
//	virtual bool be_visit(Small_Hoard& small_hoard, Type type);
//	virtual bool be_visit(Normal_Hoard& normal_hoard, Type type);
//	virtual bool be_visit(Merchant_Hoard& merchant_hoard, Type type);
//	virtual bool be_visit(Dragon_Hoard& dragon_hoard, Type type);
//	virtual bool be_visit(Restore_Health& restore_health, Type type);
//	virtual bool be_visit(Boost_Atk& boost_atk, Type type);
//	virtual bool be_visit(Boost_Def& boost_def, Type type);
//	virtual bool be_visit(Poison_Health& poison_health, Type type);
//	virtual bool be_visit(Wound_Atk& wound_atk, Type type);
//	virtual bool be_visit(Wound_Def& wound_def, Type type);
//	virtual bool be_visit(Space& space, Type type);
//	virtual bool be_visit(Vertical_Wall& vertical_wall, Type type);
//	virtual bool be_visit(Horizontal_Wall& horizontal_wall, Type type);
//	virtual bool be_visit(Tile& typeile, Type type);
//	virtual bool be_visit(Passage& passage, Type type);
//	virtual bool be_visit(Door& door, Type type);
//	virtual bool be_visit(Stair& stair, Type type);
	virtual ~Object() = 0;
    
    //virtual void notify(Subject& whoNotify) = 0; //subclass have to implement this.
    //SubscriptionType subType() const;
};

#endif
