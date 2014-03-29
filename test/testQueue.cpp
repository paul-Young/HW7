#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/Queue.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(QueueTest,EmptyConstructor){
    Queue q;
    EXPECT_EQ("",q.str());
    EXPECT_EQ(0,q.len());
}
// ---------------------------------------------------------------- //

// ------------------------- Test Enqueue ------------------------- //
TEST(QueueTest,SingleEnqueue){
    Queue q;
    Customer c(2.3,"Paul");
    q.enqueue(c);
    EXPECT_EQ("[<Customer Paul: 2.3>*]");
    EXPECT_EQ(q.len(),1);
}

TEST(QueueTest,DoubleEnqueue){
    Queue q;
    Customer c1(2.3,"Paul");
    Customer c2(2.5,"Byan");
    q.enqueue(c1);
    q.enqueue(c2);
    EXPECT_EQ("[<Customer Bryan: 2.5>*,<Customer Paul: 2.3>]");
    EXPECT_EQ(q.len(),2);
}

TEST(QueueTest,MaxEnqueue){
    Queue q;
    Customer c(0.0,"Smith");
    int length = 0;
    for (int i=0;i<8;i++){
    	c.setTime((double)i);
    	EXPECT_EQ(q.enqueue(c),1);
    	EXPECT_EQ(q.len(),++length);
    }
    c.setTime(8.0);
    EXPECT_EQ(q.enqueue(c),0)
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
    EXPECT_EQ(q.enqueue(c),0)
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
    Customer c2(2.5,"Byan");
    q.enqueue(c1);
    q.enqueue(c2);
    EXPECT_EQ(q.dequeue().str(),"<Customer Bryan: 2.5>");
    EXPECT_EQ(q.len(),1);
    EXPECT_EQ(q.dequeue().str(),"<Customer Paul: 2.3>");
    EXPECT_EQ(q.len(),0);
}

TEST(QueueTest,MaxDequeue){
    Queue q;
    Customer c(0.0,"Smith");
    int length = 0;
    for (int i=0;i<8;i++){
    	c.setTime((double)i);
    	EXPECT_EQ(q.enqueue(c),1);
    	EXPECT_EQ(q.len(),++length);
    }
    c.setTime(8.0);
    EXPECT_EQ(q.enqueue(c),0)
    EXPECT_EQ(q.dequeue().str(),"<Customer Smith: 7.0>");
}
// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
