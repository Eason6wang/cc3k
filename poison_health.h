#ifndef __POISON_HEALTH_H__
#define __POISON_HEALTH_H__
#include "potion.h"
#include "info.h"

class Poison_Health final:public Potion {
	public:
	Info modify () override;
	Poison_Health (int posx, int posy);
};

#endif


