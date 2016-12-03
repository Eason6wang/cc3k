#include"goblin.h"
#include "object.h"

Goblin::Goblin(int row, int col):
  Player{1110, 15, 20, row, col, GOBLIN}{}

bool Goblin::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
