#include"orc.h"
#include "shade.h"

Orc::Orc(int row, int col):
  Enemy{140, 20, 20, row, col, ORC}{}

bool Orc::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}
