#ifndef LOGGER_H
#define LOGGER_H
#include "Event.h"
#include "Queue.h"
#include "CustomerArrival.h"
#include "Server.h"

class Logger : public Event{
public:
	Logger(Queue *Q, Server* S, CustomerArrival* A);
	
	virtual void execute();
	
private:
	Queue* Q_;
	Server* S_;
	CustomerArrival* A_;
	double* waitTime;
	int minQueueLength;
	int maxQueueLength;
	
};


#endif // LOGGER_H
