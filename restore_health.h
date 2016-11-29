#ifndef __RESTORE_HEALTH_H__
#define __RESTORE_HEALTH_H__
#include "potion.h"
#include "info.h"

class Restore_Health final:public Potion {
	public:
	Info modify () override;
	Restore_Health (int posx, int posy, Style style,
                    std::shared_ptr<Potion> potion);
};

#endif


