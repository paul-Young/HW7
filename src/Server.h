#ifndef SERVER_H
#define SERVER_H
#include <random>
#include "Event.h"
#include "Queue.h"
#include "Simulator.h"

class Server: public Event {
public:
	Server(double mean = 7.0, Queue* queue = NULL, Simulator* sim = NULL);
	bool available();
	void startService(Customer &c);
	void execute();
	virtual ~Server();
private:
	double mean_;
	Queue* Q;
	Simulator* sim_;
	Customer current;
	bool busy;
	int count;
	double lastStart;
	double totalServiceTime;
	
	std::default_random_engine gen;
	std::exponential_distribution<> exp;

};

#endif // SERVER_H
