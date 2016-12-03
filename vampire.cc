#include"vampire.h"
#include "object.h"

Vampire::Vampire(int row, int col):
  Player{1150, 25, 25, row, col, VAMPIRE}{}

bool Vampire::visit (Object &object, Type type) {
    return object.be_visit (*this, type);
}
