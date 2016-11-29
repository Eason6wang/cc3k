#include "subject.h"
#include "observer.h"

void Subject::attach(std::shared_ptr<Observer> ob) {
	observers.emplace_back(ob);
}

void Subject::notifyObservers() {
    for(auto o : observers) {
        o->notify(*this);
    }
}

//    if (t == SubscriptionType::SwitchOnly) {
//        for(auto o : observers) {
//            if (o->subType() == SubscriptionType::SwitchOnly){
//                o->notify(*this);
//            }
//        }
//    } else {
//        for(auto o : observers) {
//            if (o->subType() == SubscriptionType::All){
//                o->notify(*this);
//            }
//        }
//    }
//}

Subject::~Subject() {}
