#include "Server.h"

void Server::startService(Customer& c){
	if (!available()){
		Q->enqueue(c);
	} else {
		// record stats
		count++;
		totalServiceTime += sim_->now()-lastStart;
		
		// reschedule
		c.setTime(sim_->now());
		lastStart = sim_->now();
		current = c;
		time_ = sim_->now() + exp(gen);
		busy = true;
		sim_->insert(this);
	}
}

void Server::execute(){

	// record stats
	count++;
	totalServiceTime += sim_->now()-lastStart;
	busy = false;
	
	// grab a customer from the queue if there is one
	if (Q->len()!=0){
		current = Q->dequeue();
		startService(current);
	}
	
	return;
	
}

bool Server::available(){return busy;}
//random_device seed;
//default_random_engine gen;
//exponential_distribution exp;
//exp(gen)
