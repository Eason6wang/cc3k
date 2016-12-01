#include"halfling.h"
#include "shade.h"

Halfling::Halfling(int row, int col):
  Enemy{140, 20, 20, row, col, HALFLING}{}

bool Halfling::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

