#include <gtest/gtest.h>
#include "../src/CustomerArrival.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(CustomerArrivalTest,EmptyConstructor){
    CustomerArrival e;
    EXPECT_EQ(0.0,e.time());
}
TEST(CustomerArrivalTest,Constructor){
	CustomerArrival e1(10.0,NULL,NULL,NULL,10,1.5);;
	EXPECT_EQ(e1.time(),1.5);
}
// ---------------------------------------------------------------- //

/*----------------------------Test id------------------------------
TEST(CustomerArrivalTest,Id){
	CustomerArrival e;
	EXPECT_EQ(0,e.id());
	
	CustomerArrival e1(1,2.0);
	EXPECT_EQ(1,e1.id());
	
	e1 = e;
	EXPECT_EQ(0,e1.id());
	
}
//----------------------------------------------------------------- */

//---------------------------Test SetTime--------------------------
TEST(CustomerArrivalTest,SetTime){
	CustomerArrival e;
	e.setTime(1.0);
	EXPECT_EQ(1.0,e.time());
	
	CustomerArrival e1=e;
	e1.setTime(2.0);
	EXPECT_EQ(2.0,e1.time());
	EXPECT_EQ(1.0,e.time());
}
//-----------------------------------------------------------------

/*---------------------------Test Operator Less Than---------------
TEST(CustomerArrivalTest,LessThan){
	CustomerArrival e1(1,1.0);
	CustomerArrival e2(2,2.0);
	EXPECT_EQ(e1<e2,true);
	EXPECT_EQ(e2<e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<e2,false);
}
//-----------------------------------------------------------------
//---------------------------Test Operator LEQ---------------------
TEST(CustomerArrivalTest,LessThanEqualTo){
	CustomerArrival e1(1,1.0);
	CustomerArrival e2(2,2.0);
	EXPECT_EQ(e1<=e2,true);
	EXPECT_EQ(e2<=e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<=e2,true);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Greater Than-----------
TEST(CustomerArrivalTest,GreaterThan){
	CustomerArrival e1(1,1.0);
	CustomerArrival e2(2,2.0);
	EXPECT_EQ(e1>e2,false);
	EXPECT_EQ(e2>e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>e2,false);
}
//-----------------------------------------------------------------
//----------------------------Test Operator GEQ-----------
TEST(CustomerArrivalTest,GreaterThanEqualTo){
	CustomerArrival e1(1,1.0);
	CustomerArrival e2(2,2.0);
	EXPECT_EQ(e1>=e2,false);
	EXPECT_EQ(e2>=e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>=e2,true
	);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Equals-----------
TEST(CustomerArrivalTest,Equals){
	CustomerArrival e1(1,1.0);
	CustomerArrival e2(2,2.0);
	EXPECT_EQ(e1==e2,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1==e2,true);
}
// ---------------------------------------------------------------- */
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
