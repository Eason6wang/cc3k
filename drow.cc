#include"drow.h"
#include "style.h"
#include "object.h"
#include "potion.h"
Drow::Drow(int row, int col):
  Player{150, 25, 15, row, col, DROW}{}

bool Drow::visit (Object &object, Type type) {
	return	object.be_visit (*this, type);
}

Info& Drow::getInfo () {
    if(!getPlayerInfo().potion){
      return Character::getInfo();
    } else {
	return getPlayerInfo().potion->modify() * 1.5;
    }
}
