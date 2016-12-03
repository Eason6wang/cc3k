#include "treasure.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "buff.h"
#include "visitexcept.h"

Treasure::Treasure (int row, int col, Style style, int gold) 
		:Item{row, col, style}, gold{gold} {}

int Treasure::getGold () { return gold; }


bool Treasure::be_visit (Shade &player, Type type) {
	return be_visit_by (*this, player, type);
}	
bool Treasure::be_visit (Drow &player, Type type) {
	return be_visit_by (*this, player, type);
}	
bool Treasure::be_visit (Troll &player, Type type) {
	return be_visit_by (*this, player, type);
}	
bool Treasure::be_visit (Vampire&player, Type type) {
	return be_visit_by (*this, player, type);
}	
bool Treasure::be_visit (Goblin &player, Type type) {
	return be_visit_by (*this, player, type);
}	

/*bool Treasure::be_visit (Shade &player, Type type) {
	be_visit<Shade> (player, type);
}

bool Treasure::be_visit (Drow &player, Type type) {
	be_visit<Drow> (player, type);
}
bool Treasure::be_visit (Vampire &player, Type type) {
	be_visit<Vampire> (player, type);
}
bool Treasure::be_visit (Troll &player, Type type) {
	be_visit<Troll> (player, type);
}
bool Treasure::be_visit (Goblin &player, Type type) {
	be_visit<Goblin> (player, type);
}*/
