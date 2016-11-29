#ifndef __CELL_H__
#define __CELL_H__
#include "object.h"

class Cell :public Object {
	public:
    Cell (int posx, int posy, Style style):Object(posx, posy, style){}
	virtual ~Cell () = default;
};

#endif
