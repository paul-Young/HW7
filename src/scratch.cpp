#include <iostream>
#include "OrderedSet.h"

using namespace std;

int main(){

    OrderedSet S;
	Event event1(1,5),event2(2,5),event3(3,5);
	S.insert(event1);
	S.insert(event2);
	S.insert(event3);
	cout << "Expect [<Event 1: 5>*, <Event 2: 5>, <Event 3: 5>]" << endl;
    cout << "Actual " << S.str() << endl;
    

return 0;
}
