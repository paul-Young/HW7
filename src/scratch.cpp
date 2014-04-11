#include <iostream>
#include "CustomerArrival.h"

using namespace std;

int main(){

	Simulator s;
	s.setup(10);
	s.doAllEvents();
   
return 0;
}
