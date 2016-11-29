#include"orc.h"
#include "shade.h"

Orc::Orc(int row, int col):
  Enemy{140, 20, 20, row, col, ORC}{}

bool Orc::visit (Object &object, Type type) {
	object.be_visit (*this, type);
}

bool Orc::be_visit(Shade& shade, Type type){ // default
	if (type == MOVE) return false;
	if (type == ATTACK) {
       int damage = Character::getDamage(shade.getInfo().atk, this->getInfo().def);
       if (this->getInfo().hp -= damage) return false;// throw
	}
    return false;
}
