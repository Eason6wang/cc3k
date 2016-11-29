#include "restore_health.h"

using namespace std;

Info Restore_Health::modify () {
	Info temp = potion->modify();
	temp.hp += 10;
	return temp;
}
	

Restore_Health::Restore_Health (int posx, int posy, Style style, shared_ptr<Potion> potion)
:Potion{posx, posy, style, potion} {}
