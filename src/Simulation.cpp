#include <iostream>
#include <sys/stat.h>
#include "Simulation.h"

using namespace std;

int main(){

	mkdir("Data",0777);
	Simulator single("Data/Arrival.dat","Data/Server.dat");
	single.setup(1000,10.0,5.0);
	single.doAllEvents();

   
return 0;
}
