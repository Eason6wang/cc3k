#include"forsaken.h"
#include "type.h"


ForSaken::ForSaken(int row, int col):
  Enemy{160, 5, 13, row, col, FORSAKEN}{}

bool ForSaken::visit (Object &object, Type type) {
    int rand = getRandom(1, 10) //increase atk every turn randomly from 1 to 10
    getInfo().atk += rand;
	return object.be_visit (*this, type);
}

