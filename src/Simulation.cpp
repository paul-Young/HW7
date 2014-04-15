#include <iostream>
#include <sys/stat.h>
#include "Simulation.h"

using namespace std;

int main(){
	mkdir("Data",0777);
	Simulator s("Data/Arrival.dat","Data/Server.dat");
	s.setup(100,5.0,5.0);
	s.doAllEvents();

   
return 0;
}
