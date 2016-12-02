#include "restore_health.h"
#include "buff.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "visitexcept.h"

Info Restore_Health::modify () {
	if (potion) {
	return potion->modify();
	} else return Info{0,0,0};
}

bool Restore_Health::be_visit (Shade &player, Type type) {
	return be_visit_health_potion<Shade> (player, type, 10);
}
bool Restore_Health::be_visit (Drow &player, Type type) {
	return be_visit_health_potion<Drow> (player, type, 10);
}
bool Restore_Health::be_visit (Vampire &player, Type type) {
	return be_visit_health_potion<Vampire> (player, type, 10);
}
bool Restore_Health::be_visit (Troll &player, Type type) {
	return be_visit_health_potion<Troll> (player, type, 10);
}
bool Restore_Health::be_visit (Goblin &player, Type type) {
	return be_visit_health_potion<Goblin> (player, type, 10);
}


	

Restore_Health::Restore_Health (int posx, int posy)
:Potion{posx, posy, RESTORE_HEALTH, nullptr} {}
