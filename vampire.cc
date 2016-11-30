#include"vampire.h"
#include "object.h"

Vampire::Vampire(int row, int col):
  Player{50, 25, 25, row, col, VAMPIRE}{}

bool Vampire::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
