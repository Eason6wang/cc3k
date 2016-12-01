#include "wound_def.h"

Info Wound_Def::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.def -= 5;
	return temp;
	} else return Info{0,0,0};
}
	

Wound_Def::Wound_Def (int posx, int posy)
:Potion{posx, posy, WOUND_DEF, nullptr} {}
