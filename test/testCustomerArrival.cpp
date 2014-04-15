#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/CustomerArrival.h"
#include "../src/Simulator.h"
#include "../src/Server.h"
#include "../src/Queue.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(CustomerArrivalTest,EmptyConstructor){
    CustomerArrival e;
    EXPECT_EQ(0.0,e.time());
}
TEST(CustomerArrivalTest,Constructor){
	CustomerArrival e1(10.0,NULL,NULL,NULL,10,1.5);
	EXPECT_EQ(e1.time(),1.5);
}
// ---------------------------------------------------------------- //

// ----------------------------Test id------------------------------
TEST(CustomerArrivalTest,Id){
	CustomerArrival e;
	EXPECT_EQ(0,e.id());
	
	CustomerArrival e1(10.0,NULL,NULL,NULL,10,2.0);
	EXPECT_EQ(0,e1.id());
}
//----------------------------------------------------------------- /

//---------------------------Test SetTime--------------------------
TEST(CustomerArrivalTest,SetTime){
	CustomerArrival e;
	e.setTime(1.0);
	EXPECT_EQ(1.0,e.time());
	
	CustomerArrival e1(10.0,NULL,NULL,NULL,10,1.0);
	e1.setTime(2.0);
	EXPECT_EQ(2.0,e1.time());
	EXPECT_EQ(1.0,e.time());
}
//-----------------------------------------------------------------

// ---------------------------Test Operator Less Than---------------
TEST(CustomerArrivalTest,LessThan){
	CustomerArrival e1;
	CustomerArrival e2;
	e1.setTime(1.0);
	e2.setTime(2.0);
	EXPECT_EQ(e1<e2,true);
	EXPECT_EQ(e2<e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<e2,false);
}
//-----------------------------------------------------------------
// ---------------------------Test Operator LEQ---------------------
TEST(CustomerArrivalTest,LessThanEqualTo){
	CustomerArrival e1;
	CustomerArrival e2;
	e1.setTime(1.0);
	e2.setTime(2.0);
	EXPECT_EQ(e1<=e2,true);
	EXPECT_EQ(e2<=e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<=e2,true);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Greater Than-----------
TEST(CustomerArrivalTest,GreaterThan){
	CustomerArrival e1;
	CustomerArrival e2;
	e1.setTime(1.0);
	e2.setTime(2.0);
	EXPECT_EQ(e1>e2,false);
	EXPECT_EQ(e2>e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>e2,false);
}
//-----------------------------------------------------------------
//----------------------------Test Operator GEQ-----------
TEST(CustomerArrivalTest,GreaterThanEqualTo){
	CustomerArrival e1;
	CustomerArrival e2;
	e1.setTime(1.0);
	e2.setTime(2.0);
	EXPECT_EQ(e1>=e2,false);
	EXPECT_EQ(e2>=e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>=e2,true
	);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Equals-----------
TEST(CustomerArrivalTest,Equals){
	CustomerArrival e1;
	CustomerArrival e2;
	e1.setTime(1.0);
	e2.setTime(2.0);
	EXPECT_EQ(e1==e2,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1==e2,true);
}
// ---------------------------------------------------------------- //

// ---------------------Test execute--------------------- //
TEST(CustomerArrivalTest,executeAvailableServer){
	Queue Q;
	Simulator s;
	Server S(5.0,&Q,&s);
	CustomerArrival A(10.0,&Q,&S,&s);
	
	A.execute();
	EXPECT_EQ(0,Q.len());
}

TEST(CustomerArrivalTest,executeBusyServer){
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

/* ---------------------Test Operator Equals--------------------- //
TEST(CustomerArrivalTest,Equals){

}
// ---------------------------------------------------------------- //
// ---------------------Test Operator Equals--------------------- //
TEST(CustomerArrivalTest,Equals){

}
// ---------------------------------------------------------------- //
// ---------------------Test Operator Equals--------------------- //
TEST(CustomerArrivalTest,Equals){

}
// ---------------------------------------------------------------- */

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
