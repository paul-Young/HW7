#include <iostream>
#include "OrderedSet.h"

using namespace std;

int main(){

    Event e1(1,2.0);
    Event e2(2,4.0);
    
    OrderedSet s;
    s.insert(e2);
    s.insert(e1);
    s.remove(1);
    cout << s.str() << endl;
    
    

return 0;
}
