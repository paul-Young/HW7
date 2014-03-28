#include "OrderedSet.h"

using namespace std;

int OrderedSet::len(){return size_;}

int OrderedSet::insert(Event &newEvent){
// pre: 
// post:
// Exception: _ORDEREDSET__SETFULL if set is full
    if (size_==0){
        elements_[0]=newEvent;
        size_++;
        return 1;
    }
    if (size_==maxsize_) throw _ORDEREDSET__SETFULL;
    // figure out index
    elements_[size_++] = newEvent;
    _insertionSort();
    
}

Event OrderedSet::removeFirst(){
	if (size_==0) throw _ORDEREDSET__EMPTYSET;
	Event firstEvent;
	firstEvent = elements_[0];
	for (int i=1;i<size_;i++) elements_[i-1]=elements_[i];
	size_--;
	return firstEvent;
}

int OrderedSet::remove(int x){
	for (int i=0;i<size_;i++){
		if ( elements_[i].id()==x ){
			for (int j=i;j<size_-1;j++){
				elements_[j] = elements_[j+1];
				size_--;
				return 1;
			}
		}
	}
	return 0;
}

string OrderedSet::str(){
    stringstream os;
    if (size_==0){
		os << "[]";
		return os.str();
    }
    os << "[";
    for (int i=0;i<size_-1;i++){
    	os << elements_[i].str();
    	if (i==0) os << "*";
    	os << ", ";
    }
    os << elements_[size_-1].str() << "]";
    return os.str();
}

void OrderedSet::_insertionSort(){
    // pre: array in the Sort object must be loaded
    // post: sort the array using insertion sort 
    for (int i=0;i<size_;i++){
        for (int j=i-1;j>=0;j--){
            if (elements_[j]>elements_[j+1]){
                swap(elements_[j],elements_[j+1]);
            } else {
                break;
            }
        }
    }
    
}

