/* Event class */

#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <sstream>

class Event {
public:
    Event(int id = 0, double time = -1.0){id_ = id;time_ = time;};
    int id();
    double time();
    void setTime(double time);
    
    bool operator<(Event &other);
    bool operator<=(Event &other);
    bool operator>(Event &other);
    bool operator>=(Event &other);
    bool operator==(Event &other);
    
    std::string str();
    
private:
    int id_;
    double time_;
};
#endif // EVENT_H

