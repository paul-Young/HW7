#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "OrderedSet.h"
#include "Event.h"

class Simulator{
public:
	Simulator();
	virtual ~Simulator();
	double now() const;
	int insert(Event *e);
	void doAllEvents();
	
	virtual void setup(int custCount, double arrivalMean = 10.0, double serviceMean = 5.0);
	
private:
	double vtime_;
	OrderedSet events;

};


#endif SIMULATOR_H
