/* OrderedSet class */

#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream>
#include <sstream>
#include "Event.h"

#define _ORDEREDSET__EMPTYSET 5
#define _ORDEREDSET__SETFULL 6

class OrderedSet {
public:
    OrderedSet(int maxsize=8)
        {maxsize_=maxsize;size_=0;elements_=new Event[maxsize];};
    ~OrderedSet()
    	{delete elements_;};
    int insert(Event& x);
    Event removeFirst();
    int remove(int x);
    int len();
    
    std::string str();
    
private:
    int maxsize_;
    int size_;
    Event *elements_;
    void _insertionSort();
};
#endif // ORDEREDSET_H

