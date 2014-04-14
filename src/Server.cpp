#include <sstream>
#include "Server.h"

using namespace std;
Server::Server(double mean, Queue* queue, Simulator* sim){
	mean_=mean;
	Q=queue; 
	sim_=sim; 
	busy=false; 
	count=0; 
	lastStart=0; 
	totalServiceTime=0; 
	time_=0;
	id_ = _SERVER_ID; 
	exp = new exponential_distribution<>(mean);
	gen = new default_random_engine(seed());
	
	status.open("Server.log",ios::out);
	status << "count  now  %busy" << endl;
}

Server::~Server(){
	delete exp;
	delete gen;
	status.close();
}

void Server::startService(Customer& c){
	if (!available()){
		Q->enqueue(c);
	} else {
		// record stats
		//totalServiceTime += sim_->now()-lastStart;
		
		// reschedule
		c.setTime(sim_->now());
		lastStart = sim_->now();
		current = c;
		busy = true;
		time_ = sim_->now() + (*exp)(*gen);
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
	
	status << count << " " << sim_->now() << " " << totalServiceTime/sim_->now() <<  endl;
	
	return;
	
}

bool Server::available(){return !busy;}
string Server::str() const{
	// post: returns the string representation of the Server class
	ostringstream os;
	os << "<Server " << id_ << ":" << time_ << ">";
	return os.str();
}
//random_device seed;
//default_random_engine gen;
//exponential_distribution exp;
//exp(gen)
