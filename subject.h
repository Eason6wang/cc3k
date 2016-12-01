#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
//#include "subscriptions.h"
#include "pos.h"
#include "playerinfo.h"
#include "info.h"

class Observer;

class Subject {
    std::vector<std::shared_ptr<Observer> > observers;
 public:
    void attach(std::shared_ptr<Observer>);
    void notifyObservers();
    virtual Pos& getPos() = 0;
    //virtual PlayerInfo getPlayerInfo();
    //virtual Info getInfo() = 0;
    virtual ~Subject();
};

#endif
