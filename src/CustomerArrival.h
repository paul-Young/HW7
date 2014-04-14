/* Louie Quicksell & Paul Young
CustomerArrival.h
CS 173 - Dr. Bressoud
*/

#ifndef CUSTOMERARRIVAL_H
#define CUSTOMERARRIVAL_H

#include <random>
#include <sstream>

#include "Event.h"
#include "Customer.h"
#include "Queue.h"
#include "Server.h"
#include "Simulator.h"

#define _CUSTOMERARRIVAL_ID 0

class CustomerArrival: public Event {

public:
	CustomerArrival(double mean = 10.0, Queue * queue = NULL, Server * server = NULL, Simulator * sim = NULL, int count = 10, double time = 0.0);
	virtual std::string str() const;
	virtual void execute();
	virtual ~CustomerArrival();

private:
	int num_;				// Count of customers generated
	double mean_;			// Customer inter arrival time
	Queue* Q;				// Access to the shared queue
	Server* S;				// Access to the server
	Simulator* sim_;		// Access to the simulator
	int count_;				// When to stop generating customers
	
	std::random_device seed;
	std::default_random_engine *gen;			// Generator of random numbers
	std::exponential_distribution<>* exp;	// Object for getting values from a particular distribution
	
	double* arrivalTimes; // keep a log of Customer arrivalTimes
	
};

#endif // CUSTOMERARRIVAL_H

