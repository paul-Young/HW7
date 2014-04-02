#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/Queue.h"
#include <iostream>
#include<string>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(QueueTest,EmptyConstructor){
    Queue q;
    //cerr << "passed Constructor" << endl;
    EXPECT_EQ("[]",q.str());
    //cerr << "passed Str" << endl;
    EXPECT_EQ(0,q.len());
    //cerr<< "passed len" <<endl;
}
// ---------------------------------------------------------------- //

// ------------------------- Test Enqueue ------------------------- //
TEST(QueueTest,SingleEnqueue){
    Queue q;
    //cerr<<"passed constructor"<<endl;
    Customer c(2.3,"Paul");
    //cerr<<"passed Customer Const"<<endl;
    q.enqueue(c);
    //cerr<<"passed enqueue"<<endl;
    EXPECT_EQ(q.str(),"[<Customer Paul: 2.3>*]");
    EXPECT_EQ(q.len(),1);
}

TEST(QueueTest,DoubleEnqueue){
    Queue q;
    Customer c1(2.3,"Paul");
    Customer c2(2.0,"Bryan");
    q.enqueue(c1);
    q.enqueue(c2);
    EXPECT_EQ("[<Customer Paul: 2.3>*, <Customer Bryan: 2>]",q.str());
    EXPECT_EQ(q.len(),2);
}

TEST(QueueTest,MaxEnqueue){
    Queue q;
    Customer c(0.0,"Smith");
    int length = 0;
    for (int i=0;i<12;i++){
    	c.setTime((double)i);
    	EXPECT_EQ(q.enqueue(c),1);
    	EXPECT_EQ(q.len(),++length);
    }
    c.setTime(12.0);
    EXPECT_EQ(q.enqueue(c),0);
}

TEST(QueueTest,MoreMaxEnqueue){
    Queue q(15);
    Customer c(0.0,"Smith");
    int length = 0;
    for (int i=0;i<15;i++){
    	c.setTime((double)i);
    	EXPECT_EQ(q.enqueue(c),1);
    	EXPECT_EQ(q.len(),++length);
    }
    c.setTime(15.0);
    EXPECT_EQ(q.enqueue(c),0);
}
// ---------------------------------------------------------------- //

// ------------------------- Test Dequeue ------------------------- //
TEST(QueueTest,EmptyDequeue){
    Queue q;
	EXPECT_THROW(q.dequeue(),int);
}

TEST(QueueTest,SingleDequeue){
    Queue q;
    Customer c(2.3,"Paul");
    q.enqueue(c);
    EXPECT_EQ(q.dequeue().str(),"<Customer Paul: 2.3>");
    EXPECT_EQ(q.len(),0);
}

TEST(QueueTest,DoubleDequeue){
    Queue q;
    Customer c1(2.3,"Paul");
    Customer c2(2.5,"Bryan");
    q.enqueue(c1);
    q.enqueue(c2);
    EXPECT_EQ(q.dequeue().str(),"<Customer Paul: 2.3>");
    EXPECT_EQ(q.len(),1);
    EXPECT_EQ(q.dequeue().str(),"<Customer Bryan: 2.5>");
    EXPECT_EQ(q.len(),0);
}

TEST(QueueTest,MaxDequeue){
    Queue q;
    Customer c(0.5,"Smith");
    int length = 0;
    for (int i=0;i<12;i++){
    	c.setTime((double)i);
    	EXPECT_EQ(q.enqueue(c),1);
    	EXPECT_EQ(q.len(),++length);
    }
    c.setTime(13.0);
    EXPECT_EQ(q.enqueue(c),0);
    EXPECT_EQ(q.dequeue().str(),"<Customer Smith: 0>");
    EXPECT_EQ(q.dequeue().str(),"<Customer Smith: 1>");
}

// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
