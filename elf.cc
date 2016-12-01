#include"elf.h"
#include "shade.h"

Elf::Elf(int row, int col):
  Enemy{140, 20, 20, row, col, ELF}{}

bool Elf::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}

