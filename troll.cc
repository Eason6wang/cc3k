#include"troll.h"
#include "object.h"

Troll::Troll(int row, int col):
  Player{120, 25, 15, row, col, TROLL}{}

bool Troll::visit (Object &object, Type type) {
   // gain 5 hp every turn
   int & hp = getInfo().hp;
   if(hp < 115){
       hp += 5;
   } else {
       hp = 120;
   }
    return object.be_visit (*this, type);
}
