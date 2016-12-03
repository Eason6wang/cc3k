#include"troll.h"
#include "object.h"

Troll::Troll(int row, int col):
  Player{1120, 25, 15, row, col, TROLL}{}

bool Troll::visit (Object &object, Type type) {
   // gain 5 hp every turn
   int & hp = getInfo().hp;
   if(hp < 115){
       hp += 5;
       getPlayerInfo().action += "PC gains 5 HP every turn. ";
   } else if(115 <= hp && hp < 120){
       hp = 120;
       getPlayerInfo().action += "PC gains 5 HP every turn. ";
   }
    return object.be_visit (*this, type);
}
