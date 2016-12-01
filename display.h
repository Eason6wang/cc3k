#ifndef __DISPLAY_H_
#define __DISPLAY_H_
#include <memory>
class Window;
class Panel;
class Floor;

struct Display {
	std::shared_ptr<Window> w;
	std::shared_ptr<Panel> p;
	void display(std::shared_ptr<Window> w);
	void display(std::shared_ptr<Panel> p);
	void display();
};

#endif
