#include"eason.h"
#include "type.h"

// nightelf can be invisible
Eason::Eason(int row, int col):
  Player{111, 29, 17, row, col, EASON}{}

bool Eason::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

