#include "Event.h"

using namespace std;

/* Comparison operators for Event class
post: return true or false
*/
bool Event::operator<(Event &other){
    return( time_<other.time() );
}
bool Event::operator<=(Event &other){
    return( time_<=other.time() );
}
bool Event::operator>(Event &other){
    return( time_>other.time() );
}
bool Event::operator>=(Event &other){
    return( time_>=other.time() );
}
bool Event::operator==(Event &other){
	return( time_==other.time() );
}

string Event::str(){
    stringstream os;
    os << "<Event " << id_ << ": " << time_ << ">";
    return os.str();
}

int Event::id(){return id_;}
double Event::time(){return time_;}
void Event::setTime(double time){time_=time;}
