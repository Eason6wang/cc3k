#include"troll.h"
#include "object.h"

Troll::Troll(int row, int col):
  Player{120, 25, 15, row, col, TROLL}{}

bool Troll::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
