#include "Simulator.h"
#include "Queue.h"
#include "Server.h"
#include "CustomerArrival.h"

using namespace std;

Simulator::~Simulator(){}

void Simulator::setup(int custCount, double arrivalMean, double serviceMean){
	/* post: setup environment for checkout simulation
		1. construct a shared queue of custCount Customers
		2. construct a Server and a CustomerArrival object
		3. insert the CustomerArrival object into the OrderedSet
	*/
	Queue Q(custCount);
	Server S(serviceMean,&Q,this);
	CustomerArrival A(arrivalMean,&Q,&S,this,custCount,now());
	insert(&A);
}

int Simulator::insert(EPointer event){
	events.insert(event);
}

void Simulator::doAllEvents(){
	// post: repeated removes the first event from the OrderedSet, updates virtual time to the time of the event and execute the event.
	while (events.len()>0){
		Event cur = *events.removeFirst();
		vtime_ = cur.time();
		cur.execute();
	}
}
double Simulator::now() const {return vtime_;}


