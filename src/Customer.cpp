#include "Customer.h"
#include <iostream>
#include <sstream>

using namespace std;

string Customer::str() const{
	stringstream s;
	s << "<Customer "<<label_<<": "<<time_<<">"<<endl;
	return s.str();	
}
	
