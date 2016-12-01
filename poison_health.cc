#include "poison_health.h"

using namespace std;

Info Poison_Health::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.hp -= 10;
	return temp;
	} else return Info{0,0,0};
}
	

Poison_Health::Poison_Health (int posx, int posy)
:Potion{posx, posy, POISON_HEALTH, nullptr} {}
