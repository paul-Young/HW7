#include "Event.h"

using namespace std;

/*
bool Event::operator<(Event &other){
    // pre:
    // post:
    // Exception
    
    
    return true;
}
*/

string Event::str(){
    stringstream os;
    os << "<Event: " << id_ << ": " << time_ << ">";
    return os.str();
}

int Event::id(){return id_;}
double Event::time(){return time_;}
void Event::setTime(double time){time_=time;}
