/* Louie Quicksell & Paul Young
CustomerArrival.h
CS 173 - Dr. Bressoud */

#include "CustomerArrival.h"

using namespace std;

CustomerArrival::CustomerArrival(double mean, Queue * queue, Server * server, Simulator * sim, int count, double time)		// Constructor
{
	mean_ = mean;
	Q = queue;
	S = server;
	sim_ = sim;
	count_ = count;
	time_ = time;
	id_ = _CUSTOMERARRIVAL_ID;
	exp = new exponential_distribution<>(mean);
	gen = new default_random_engine(seed());
	
	arrivalTimes = new double[count];
}

CustomerArrival::~CustomerArrival(){
	delete exp;
	delete gen;
	delete arrivalTimes;
}

void CustomerArrival::execute(){

	// create the new Customer with appropriate time and label
	ostringstream convert;
	convert << ++num_;
	Customer cust(sim_->now(), convert.str());
	arrivalTimes[num_] = sim_->now();
	
	cout << "Arrival: " << num_ << " " << cust.str() << 
		" Server: " << S->available() << endl;
	
	// decide what to do with the Customer
	if (S->available()){
		S->startService(cust);
	}else{
		Q->enqueue(cust);
	}
	
	// schedule next CustomerArrival if allowed
	if (num_ < count_){
		time_ = sim_->now() + (*exp)(*gen);
		sim_->insert(this);
	}
	
	return;
}

string CustomerArrival::str() const{
	// post: returns the string representation of the CustomerArrival class
	ostringstream os;
	os << "<Arrival " << id_ << ":" << time_ << ">";
	return os.str();
}

	
