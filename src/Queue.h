/*  Queue.h
Author: Bryan Fowler
Date: 3/31/14
CS 173  */

#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include"Customer.h"

class Queue
{
	public:
		Queue(int maxsize = 12);//
		~Queue(){delete people_;};//
		int enqueue(Customer &x);
		Customer dequeue();
		int len();
		std::string str();
	
	private:
		int start_, tail_;
		int length_;
		int maxsize_;
		Customer *people_;
};

#endif	
			
