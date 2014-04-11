/* Louie Quicksell & Paul Young
CustomerArrival.h
CS 173 - Dr. Bressoud */
//STILL
//INCOMPLETE
//CHECK CONSTRUCTOR
//AND EXECUTE
#include "CustomerArrival.h"

using namespace std;

CustomerArrival::CustomerArrival(double mean, Queue * queue, Server * server, Simulator * sim, int count, double time)		// Constructor
{
	mean_ = mean;
	count_ = count;
	Q = queue;
	S = server;
	sim_ = sim;
	
	Customer c(time,"0");
	Q->enqueue(c);
	num_ = 1;
	
	/*
	Customer cust = Q->dequeue();
	double time_ = time;	
	if (Q->len() == 0 && S->available() == true){
		S->startService(cust);
		sim_->insert(this);
	}
	*/
}

void CustomerArrival::excecute(){

	// create the new Customer with appropriate time and label
	ostringstream convert;
	convert << count_;	
	Customer cust(sim_->now(), convert.str()); 
	cout << cust.str() << " has arrived!" << endl;
	
	// decide what to do with the Customer
	if (S->available() == true){
		S->startService(cust);
	}else{
		Q->enqueue(cust);
	}
	
	// schedule next CustomerArrival if allowed
	if (num_ < count_){
		time_ = sim_->now() + exp(gen);
		sim_->insert(this);
		num_++;
	}
	
	return;
}

string CustomerArrival::str() const{
	ostringstream os;
	os << "<Arrival " << num_ << ":" << time_ << ">";
	return os.str();
}

	
