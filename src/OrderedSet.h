/* OrderedSet class */

#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream>
#include <sstream>
#include "Event.h"

class OrderedSet {
public:
    OrderedSet(int maxsize=8){maxsize_=maxsize; size_=0;};
    int insert(Event& x);
    Event removeFirst();
    int remove(int x);
    int len();
    
    std::string str();
    
private:
    int maxsize_;
    int size_;
    Event *events_;
};
#endif // ORDEREDSET_H

