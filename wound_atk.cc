#include "wound_atk.h"

using namespace std;

Info Wound_Atk::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.hp -= 5;
	return temp;
	} else return Info{0,0,0};
}
	

Wound_Atk::Wound_Atk (int posx, int posy)
:Potion{posx, posy, WOUND_ATK, nullptr} {}
