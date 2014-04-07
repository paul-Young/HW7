#include "CustomerArrival.h"

CustomerArrival::CustomerArrival(double mean, Queue* queue, int id, double time)
	: Event(id,time) // initializer list
{
	mean_ = mean;
	Q = queue;
}

void CustomerArrival::execute(){
	
}
