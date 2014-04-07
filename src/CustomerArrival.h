/* Event class */

#ifndef CUSTOMERARRIVAL_H
#define CUSTOMERARRIVAL_H
#include "Event.h"
#include "Queue.h"

class CustomerArrival : public Event {
public:
    CustomerArrival(double mean = 10.0, Queue* queue=NULL,
    			int id = 0, double time = 10.0);
    virtual ~CustomerArrival(){};
    virtual void execute();
    
private:
	int num_;
	double mean_;
	Queue* Q;
	
	int count_;
};

#endif // CUSTOMERARRIVAL_H

