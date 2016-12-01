#include"dwarf.h"
#include "shade.h"

Dwarf::Dwarf(int row, int col):
  Enemy{140, 20, 20, row, col, DWARF}{}

bool Dwarf::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}

