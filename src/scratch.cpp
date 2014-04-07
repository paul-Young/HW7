#include <iostream>
#include "OrderedSet.h"

using namespace std;

int main(){

    OrderedSet S;
	Event event1(1,5), event2(2,4.5);
	S.insert(&event1);
	S.insert(&event2);
   
return 0;
}
