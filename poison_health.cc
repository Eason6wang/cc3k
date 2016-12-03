#include "poison_health.h"
#include "buff.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "visitexcept.h"

using namespace std;
/*
bool Poison_Health::be_visit (Shade &player, Type type) {
	return be_visit_health_potion (player, type, 10);
}
bool Poison_Health::be_visit (Drow &player, Type type) {
	return be_visit_health_potion (player, type, 10);
}
bool Poison_Health::be_visit (Vampire &player, Type type) {
	return be_visit_health_potion (player, type, 10);
}
bool Poison_Health::be_visit (Troll &player, Type type) {
	return be_visit_health_potion (player, type, 10);
}
bool Poison_Health::be_visit (Goblin &player, Type type) {
	return be_visit_health_potion (player, type, 10);
}
*/	

Poison_Health::Poison_Health (int posx, int posy)
:Potion{posx, posy, POISON_HEALTH} {}
