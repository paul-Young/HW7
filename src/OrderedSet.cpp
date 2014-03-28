#include "OrderedSet.h"

using namespace std;

int OrderedSet::len(){return size_;}

string OrderedSet::str(){
    stringstream os;
    os << "[]";
    return os.str();
}

int insert(Event &x){
    if (size_==0){
        events_[0]=x;
        size_++;
        return 1;
    }
}

