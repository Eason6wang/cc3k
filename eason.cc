#include"eason.h"
#include "type.h"

Eason::Eason(int row, int col):
  Player{111, 200, 17, row, col, EASON}{}

bool Eason::visit (Object &object, Type type) {
	getInfo().atk -= 1;
	return object.be_visit (*this, type);
}

