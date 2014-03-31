#include "Customer.h"
#include <iostream>
#include <sstream>

using namespace std;

string Customer::str() const{
	stringstream s;
	s << "<Customer "<<label_<<": "<<time_<<">";
	return s.str();	
}
	
double Customer::time() const{return time_;}

string Customer::label() const{return label_;}

void Customer::setTime(double time){time_=time;}
