#include <gtest/gtest.h>
#include "../src/Event.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(EventTest,EmptyConstructor){
    Event e;
    EXPECT_EQ(0,e.id());
    EXPECT_EQ(-1.0,e.time());
    
}
TEST(EventTest,Constructor){
	Event e1(1,5);
	EXPECT_EQ(e1.id(),1);
	EXPECT_EQ(e1.time(),5.0);
}
// ---------------------------------------------------------------- //
// -------------------------- Test str ---------------------------- //
TEST(EventTest,Str){
    Event e;
    EXPECT_EQ("<Event 0: -1>",e.str());
    
    Event e1(1,2.0);
    EXPECT_EQ("<Event 1: 2>",e1.str());
}
//-----------------------------------------------------------------
//----------------------------Test id------------------------------
TEST(EventTest,Id){
	Event e;
	EXPECT_EQ(0,e.id());
	
	Event e1(1,2.0);
	EXPECT_EQ(1,e1.id());
	
	e1 = e;
	EXPECT_EQ(0,e1.id());
	
}
//-----------------------------------------------------------------
//----------------------------Test Time----------------------------
TEST(EventTest,Time){
	Event e;
	EXPECT_EQ(-1.0,e.time());
	
	Event e1(1,2.0);
	EXPECT_EQ(2.0,e1.time());
	
	e1 = e;
	EXPECT_EQ(-1.0,e1.time());
}
//-----------------------------------------------------------------
//---------------------------Test SetTime--------------------------
TEST(EventTest,SetTime){
	Event e;
	e.setTime(1.0);
	EXPECT_EQ(1.0,e.time());
	
	Event e1=e;
	e1.setTime(2.0);
	EXPECT_EQ(2.0,e1.time());
	EXPECT_EQ(1.0,e.time());
}
//-----------------------------------------------------------------
//---------------------------Test Operator Less Than---------------
TEST(EventTest,LessThan){
	Event e1(1,1.0);
	Event e2(2,2.0);
	EXPECT_EQ(e1<e2,true);
	EXPECT_EQ(e2<e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<e2,false);
}
//-----------------------------------------------------------------
//---------------------------Test Operator LEQ---------------------
TEST(EventTest,LessThanEqualTo){
	Event e1(1,1.0);
	Event e2(2,2.0);
	EXPECT_EQ(e1<=e2,true);
	EXPECT_EQ(e2<=e1,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1<=e2,true);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Greater Than-----------
TEST(EventTest,GreaterThan){
	Event e1(1,1.0);
	Event e2(2,2.0);
	EXPECT_EQ(e1>e2,false);
	EXPECT_EQ(e2>e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>e2,false);
}
//-----------------------------------------------------------------
//----------------------------Test Operator GEQ-----------
TEST(EventTest,GreaterThanEqualTo){
	Event e1(1,1.0);
	Event e2(2,2.0);
	EXPECT_EQ(e1>=e2,false);
	EXPECT_EQ(e2>=e1,true);
	e2.setTime(1.0);
	EXPECT_EQ(e1>=e2,true);
}
//-----------------------------------------------------------------
//----------------------------Test Operator Equals-----------
TEST(EventTest,Equals){
	Event e1(1,1.0);
	Event e2(2,2.0);
	EXPECT_EQ(e1==e2,false);
	e2.setTime(1.0);
	EXPECT_EQ(e1==e2,true);
}
// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
