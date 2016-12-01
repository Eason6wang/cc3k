#include "boost_atk.h"

Info Boost_Atk::modify () {
	if (potion) {
	Info temp = potion->modify();
	temp.atk += 5;
	return temp;
	} else return Info{0,0,0};
}
	

Boost_Atk::Boost_Atk (int posx, int posy)
:Potion{posx, posy, BOOST_ATK, nullptr} {}
