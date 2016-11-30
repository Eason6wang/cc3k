#ifndef __PANEL_H_
#define __PANEL_H_
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "player.h"

class Subject;
class Object;

class Panel final:public Observer {
	std::string race, action;
	int gold,floor,hp,atk,def;
    std::shared_ptr<Player> player;
	public:
	Panel(std::shared_ptr<Player> player);
    void notify(Subject &whoNotified) override;
	//SubscriptionType subType() const override;

	//~Panel();

	friend std::ostream &operator<<(std::ostream &out, const Panel &panel);
};

#endif
