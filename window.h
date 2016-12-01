#ifndef __WINDOW_H_
#define __WINDOW_H_
#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include "subscriptions.h"

class Object;

class Window: public Observer {
	std::vector<std::vector<char>> theDisplay;
	const int width,height;
	Pos p = Pos{-1, -1, SHADE};

	public:
    Window(std::string file);
	
	void notify(Subject &whoNotify) override;
	//since we there is only one type of observer in the program.
	//SubscriptionType subType() const override;

	~Window();
    
    //SubscriptionType subType() const override;

	friend std::ostream &operator<<(std::ostream &out, const Window &w);
};

#endif

