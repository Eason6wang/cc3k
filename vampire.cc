#include"vampire.h"
#include "object.h"

Vampire::Vampire(int row, int col):
  Player{50, 25, 25, row, col, VAMPIRE}{}

bool Vampire::visit (Object &object, Type type) {
    // gain 5 hp every attack
    getInfo().hp += 5;
    bool result = object.be_visit (*this, type);
    if(type == ATTACK && result){
	return true;
    } else {
      getInfo().hp -= 5;	
      return result;
    }
}
