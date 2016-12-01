#include "restore_health.h"

using namespace std;

Info Restore_Health::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.hp += 10;
	return temp;
	} else return Info{0,0,0};
}
	

Restore_Health::Restore_Health (int posx, int posy)
:Potion{posx, posy, RESTORE_HEALTH, nullptr} {}
