#include"nightelf.h"
#include "type.h"

// nightelf can be invisible
NightElf::NightElf(int row, int col):
  Enemy{111, 29, 17, row, col, NIGHTELF}{}

bool NightElf::visit (Object &object, Type type) {
	return object.be_visit (*this, type);
}

