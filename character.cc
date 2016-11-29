#include"character.h"

Character::Character(int hp, int atk, int def, int row, int col, Style style):
   	information{hp, atk, def}, Object{row,col,style}{}

Info& Character::getInfo(){
  return information;
}

int Character::getDamage(int atk, int def) {
	return ((100 / (100 + def)) * atk );
}
