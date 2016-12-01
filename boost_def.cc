#include "boost_def.h"

Info Boost_Def::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.def += 5;
	return temp;
	} else return Info{0,0,0};
}
	

Boost_Def::Boost_Def (int posx, int posy)
:Potion{posx, posy, BOOST_DEF, nullptr} {}
