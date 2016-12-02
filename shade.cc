#include"shade.h"
#include "object.h"

using namespace std;



Shade::Shade(int row, int col):
  Player{1205, 25, 25, row, col, SHADE}{}

bool Shade::visit(Object & obj, Type type){
	return obj.be_visit(*this, type);
}
