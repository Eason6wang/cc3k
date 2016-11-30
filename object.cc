#include "object.h"
using namespace std;


//Info& getInfo(){
//    Info o {0,0,0};
//    return o;
//};

Pos Object::getPos() { return pos; }

Object::Object(int posx, int posy, Style style): pos{posx,posy, style, false, nullptr}{}
    
Object::~Object () {}

void Object::flip () { pos.isRead = true; }

void Object::set_last (std::shared_ptr<Object> last) {
	pos.last = last;
};

bool Object::visit_objects(Type type){ return false; }
bool Object::visit(Object &object, Type type){ return false; }
//be_visit
bool Object::be_visit(Shade& shade, Type type){ return false; }
bool Object::be_visit(Drow& drow, Type type){ return false; }
bool Object::be_visit(Vampire& vampire, Type type){ return false; }
bool Object::be_visit(Troll& typeroll, Type type){ return false; }
bool Object::be_visit(Goblin& goblin, Type type){ return false; }
bool Object::be_visit(Human& human, Type type){ return false; }
bool Object::be_visit(Dwarf& dwarf, Type type){ return false; }
bool Object::be_visit(Halfling& halfling, Type type){ return false; }
bool Object::be_visit(Elf& elf, Type type){ return false; }
bool Object::be_visit(Orc& orc, Type type){ return false; }
//bool Object::be_visit(Dragon& dragon, Type type){ return false; }
bool Object::be_visit(Merchant& merchant, Type type){ return false; }
//bool Object::be_visit(Small_Hoard& small_hoard, Type type){ return false; }
//bool Object::be_visit(Normal_Hoard& normal_hoard, Type type){ return false; }
//bool Object::be_visit(Merchant_Hoard& merchant_hoard, Type type){ return false; }
//bool Object::be_visit(Dragon_Hoard& dragon_hoard, Type type){ return false; }
//bool Object::be_visit(Restore_Health& restore_health, Type type){ return false; }
//bool Object::be_visit(Boost_Atk& boost_atk, Type type){ return false; }
//bool Object::be_visit(Boost_Def& boost_def, Type type){ return false; }
//bool Object::be_visit(Poison_Health& poison_health, Type type){ return false; }
//bool Object::be_visit(Wound_Atk& wound_atk, Type type){ return false; }
//bool Object::be_visit(Wound_Def& wound_def, Type type){ return false; }
//bool Object::be_visit(Space& space, Type type){ return false; }
//bool Object::be_visit(Vertical_Wall& vertical_wall, Type type){ return false; }
//bool Object::be_visit(Horizontal_Wall& horizontal_wall, Type type){ return false; }
//bool Object::be_visit(Tile& typeile, Type type){ return false; }
//bool Object::be_visit(Passage& passage, Type type){ return false; }
//bool Object::be_visit(Door& door, Type type){ return false; }
//bool Object::be_visit(Stair& stair, Type type){ return false; }


/*SubscriptionType Object::subType() const {
    return SubscriptionType::SwitchOnly;
}*/
