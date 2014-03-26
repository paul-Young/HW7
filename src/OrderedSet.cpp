#include "OrderedSet.h"

using namespace std;

int OrderedSet::len(){return size_;}

string OrderedSet::str(){
    stringstream os;
    os << "[]";
    return os.str();
}
