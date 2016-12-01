#ifndef _BUFF_H_
#define _BUFF_H_
#include <cstdlib>
#include <iostream>
#include <memory>
class Object;
void clearScreen();

int getRandom(int min, int max);

int getDamage(int, int);


bool compare(std::shared_ptr<Object> ob1,std::shared_ptr<Object> ob2);

#endif
