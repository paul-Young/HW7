/*  Queue.h
Author: Bryan Fowler
Date: 3/31/14
CS 173  */

#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<sstream>
#include "Customer.h"

#define _QUEUE_MAXSIZE 1000

class Queue{
	public:
		Queue(int maxsize = _QUEUE_MAXSIZE);
		~Queue();
		int enqueue(Customer &x);
		Customer dequeue();
		int len();
		std::string str();
	
	private:
		int maxsize_;
		int start_;
		int tail_;
		int length_;
		Customer *people_;
};

#endif	
			
