#ifndef __NIGHTELF_H_
#define __NIGHTELF_H_
#include"player.h"
#include "style.h"
#include "type.h"
class Object;


class NightElf: public Player{
public:
    NightElf(int row, int col);
    bool visit(Object&, Type type);
};

#endif
