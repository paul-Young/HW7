#include <iostream>
#include "Queue.h"
#include "Server.h"
#include "CustomerArrival.h"
#include "Simulator.h"
#include "Event.h"

using namespace std;

int main(){

	Simulator s;
	s.setup(10);
	s.doAllEvents();
	
	/*
	Simulator sim;
	Queue Q(10);
	Server S(5,&Q,&sim);
	
	CustomerArrival A(10,&Q,&S,&sim,10,0);
	Event* e = &A;
	e->execute();
	*/

   
return 0;
}
