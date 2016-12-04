#include "aaron.h"
#include "object.h"
#include "style.h"

Aaron::Aaron (int row, int col):
  Player{10000, 1000, 100, row, col, AARON}{}

bool Aaron::visit(Object & obj, Type type){
	return obj.be_visit(*this, type);
}

