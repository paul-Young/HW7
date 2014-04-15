#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/CustomerArrival.h"
#include "../src/Simulator.h"
#include "../src/Server.h"
#include "../src/Queue.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(ServerTest,EmptyConstructor){
    Server e;
    EXPECT_EQ(1,e.id());
    EXPECT_EQ(0.0,e.time());
    
}
TEST(ServerTest,Constructor){
	Server e1(1, NULL, NULL);
	EXPECT_EQ(e1.id(),1);
	EXPECT_EQ(e1.time(),0.0);
}

// -------------------------- Test available ---------------------------- //
TEST(ServerTest,availableEmptyConstructor){
    Server e;
    EXPECT_TRUE(e.available());
}    
/*TEST(ServerTest, available){
	Server e;
	Customer c;
	e.startService(c);
	EXPECT_FALSE(e.available());
	e.execute();
	EXPECT_TRUE(e.available());
}*/

//----------------------------Test startService------------------------------//
TEST(ServerTest,startService){
	Simulator s;
	Queue Q;
	Server e(7.0,&Q,&s);
	Customer c(4.0);
	e.startService(c);
	EXPECT_FALSE(e.available());
	e.execute();
	EXPECT_TRUE(e.available());
}

TEST(ServerTest, startServiceBusyServer){
	Simulator s;
	Queue Q;
	Server e(7.0, &Q, &s);
	Customer c, c1;
	e.startService(c);
	EXPECT_FALSE(e.available());	
	e.startService(c1);
	EXPECT_EQ(Q.len(), 1);
}

/*TEST(ServerTest, startServiceFullQueue){
	Queue * q;	
	Server e(7.0, q, NULL);
	Customer c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13;
	e.startService(c);
	e.startService(c1);
	e.startService(c2);
	e.startService(c3);
	e.startService(c4);
	e.startService(c5);
	e.startService(c6);
	e.startService(c7);
	e.startService(c8);
	e.startService(c9);
	e.startService(c10);
	e.startService(c11);
	e.startService(c12);
	EXPECT_THROW(e.startService(c13), int);
}*/
/*
TEST(ServerTest, startServiceReschedule){
	Queue * q;
	Simulator * sim;
	Server e(7.0, q, sim);
	Customer c;
	e.startService(c);
	EXPECT_TRUE(sim.checkEvents(e));
}*/	

/*TEST(ServerTest, startServiceTime){
	Queue Q;
	Simulator s;
	Server e(7.0, &Q, &s);
	Customer c(2.0);
	e.startService(c);
	EXPECT_EQ(s.now(),2.0);
}*/

//----------------------------Test execute----------------------------


//-----------------------------------------------------------------*/
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
