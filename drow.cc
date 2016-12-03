#include"drow.h"
#include "style.h"
#include "object.h"
#include "potion.h"
Drow::Drow(int row, int col):
  Player{1150, 25, 15, row, col, DROW}{}

bool Drow::visit (Object &object, Type type) {
	return	object.be_visit (*this, type);
}

