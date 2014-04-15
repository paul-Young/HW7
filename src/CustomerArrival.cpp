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
	
	busyServer = 0;
	status.open("ArrivalReport.dat",ios::out);
	status << "now  count  %busy  Q.len()" << endl;
}

CustomerArrival::~CustomerArrival(){
	delete exp;
	delete gen;
	status.close();
}

void CustomerArrival::execute(){

	// create the new Customer with appropriate time and label
	ostringstream convert;
	convert << ++num_;
	Customer cust(sim_->now(), convert.str());
	
	// decide what to do with the Customer
	if (S->available()){
		S->startService(cust);
	}else{
		busyServer += 1;
		Q->enqueue(cust);
	}
	
	// schedule next CustomerArrival if allowed
	if (num_ < count_){
		time_ = sim_->now() + (*exp)(*gen);
		sim_->insert(this);
	}
	
	reportStatus();
	
	return;
}

void CustomerArrival::reportStatus(){
	status << sim_->now() << ": " << num_ << " " << busyServer/(double)num_ << " " << Q->len() << " " << endl;
}

string CustomerArrival::str() const{
	// post: returns the string representation of the CustomerArrival class
	ostringstream os;
	os << "<Arrival " << id_ << ":" << time_ << ">";
	return os.str();
}

	
