#ifndef __DISPLAY_H_
#define __DISPLAY_H_

class Object;
class Window;
class Panel;

struct Display {
    std::shared_ptr<Window> w;
    std::shared_ptr<Panel> p;
};

#endif
