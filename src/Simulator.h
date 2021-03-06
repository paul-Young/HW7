#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "OrderedSet.h"
#include "Event.h"

class Queue;
class Server;
class CustomerArrival;

class Simulator{
public:
	Simulator(std::string arrivalFile = "ArrivalReport.dat", std::string serverFile = "ServerReport.dat", bool surpressOutput = false)
		{vtime_=0; arrivalFile_ = arrivalFile; serverFile_ = serverFile;surpressOutput_=surpressOutput;};
	virtual ~Simulator();
	double now() const;
	int insert(EPointer e);
	void doAllEvents();
	
	virtual void setup(int custCount, double arrivalMean = 10.0, double serviceMean = 5.0);
	
private:
	double vtime_;
	OrderedSet events;
	std::string arrivalFile_, serverFile_;
	bool surpressOutput_;
	Queue* Q;
	Server* S;
	CustomerArrival* A;
};


#endif // SIMULATOR_H
