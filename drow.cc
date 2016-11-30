#include"drow.h"
#include "style.h"
#include "object.h"

Drow::Drow(int row, int col):
  Player{150, 25, 15, row, col, DROW}{}

bool Drow::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
