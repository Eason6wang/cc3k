#include"nightelf.h"
#include "type.h"


// nightelf can be invisible
NightElf::NightElf(int row, int col):
  Player{111, 29, 17, row, col, NIGHTELF}{}

bool NightElf::visit (Object &object, Type type) {
    if((time / 20) % 2 == 0){
	getInfo().hp += 5;
    }
    time++;
    return object.be_visit (*this, type);
}

