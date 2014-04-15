#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/CustomerArrival.h"
#include "../src/Simulator.h"
#include "../src/Server.h"
#include "../src/Queue.h"
#include <iostream>

using namespace std;

// ---------------------Test execute--------------------- //
TEST(SimulatorTest,10Customers){
	Simulator s;
	s.setup(10);
	s.doAllEvents();
}

TEST(SimulatorTest,executeBusyServer){
	Queue Q;
	Simulator s;
	Server S(5.0,&Q,&s);
	CustomerArrival A(10.0,&Q,&S,&s);
	Customer c(1,"Paul");
	S.startService(c);
	
	A.execute();
	EXPECT_EQ(1,Q.len());
}
// ---------------------------------------------------------------- //

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
