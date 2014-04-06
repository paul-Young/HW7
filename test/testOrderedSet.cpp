#include <gtest/gtest.h>
#include "../src/OrderedSet.h"
#include <iostream>

using namespace std;
//------------------------------Test Constructor---------------------------
TEST(OrderedSetTest,EmptyConstructor){
	OrderedSet S;
	EXPECT_EQ(S.str(),"[]");
	EXPECT_EQ(S.len(),0);
}
//-------------------------------------------------------------------------
//------------------------------Test Insert--------------------------------
TEST(OrderedSetTest,InsertOneEvent){
	OrderedSet S;
	Event event;
	EXPECT_EQ(S.insert(&event),1);
	EXPECT_EQ(S.str(),"[<Event 0: -1>*]");
	
	OrderedSet S1;
	Event event1(1,5);
	EXPECT_EQ(S1.insert(&event1),1);
	EXPECT_EQ(S1.str(),"[<Event 1: 5>*]");
		
}

TEST(OrderedSetTest,InsertMultipleEvents){
	OrderedSet S;
	Event event1(1,5), event2(2,4.5);
	S.insert(&event1);
	S.insert(&event2);
	EXPECT_EQ(S.str(),"[<Event 2: 4.5>*, <Event 1: 5>]");
}
TEST(OrderedSetTest,InsertMultipleSameEvents){
	OrderedSet S;
	Event event1(1,5),event2(2,5),event3(3,5);
	S.insert(&event1);
	S.insert(&event2);
	S.insert(&event3);
	EXPECT_EQ(S.str(),"[<Event 1: 5>*, <Event 2: 5>, <Event 3: 5>]");
}
TEST(OrderedSetTest,InsertToFullSet){
	OrderedSet S(2);
	Event event1(1,5), event2(2,5),event3(3,5);
	S.insert(&event1);
	S.insert(&event2);
	EXPECT_EQ(S.insert(&event3),0);
}
TEST(OrderedSetTest,InsertMultipleEventsSameId){
	OrderedSet S;
	Event event1(1,5), event2(1,4.5);
	S.insert(&event1);
	S.insert(&event2);
	EXPECT_EQ(S.str(),"[<Event 1: 4.5>*]");
}
//------------------------------------------------------------------------
//-------------------------------Test RemoveFirst-------------------------
TEST(OrderedSetTest,EmptyRemoveFirst){
	OrderedSet S;
	EXPECT_THROW(S.removeFirst(),int);
}
TEST(OrderedSetTest,RemoveFirstFromSingleElementSet){
	OrderedSet S;
	Event event(1,5);
	S.insert(&event);
	EXPECT_EQ(S.removeFirst()->str(),"<Event 1: 5>");
	EXPECT_EQ(S.str(),"[]");
}
TEST(OrderedSetTest,RemoveFirst){
	OrderedSet S;
	Event event1(1,5),event2(2,4);
	S.insert(&event1);
	S.insert(&event2);
	EXPECT_EQ(S.removeFirst()->str(),"<Event 2: 4>");
	EXPECT_EQ(S.str(),"[<Event 1: 5>*]");
}
//-------------------------------------------------------------------------
//------------------------------Test Remove--------------------------------
TEST(OrderedSetTest,RemoveFromEmpty){
	OrderedSet S;
	EXPECT_EQ(S.remove(1),0);
}
TEST(OrderedSetTest,Remove){
	OrderedSet S;
	Event event1(1,5),event2(2,5),event3(3,5);
	S.insert(&event1);
	S.insert(&event2);
	S.insert(&event3);
	EXPECT_EQ(S.str(),"[<Event 1: 5>*, <Event 2: 5>, <Event 3: 5>]");
	EXPECT_EQ(S.remove(2),1);
	EXPECT_EQ(S.str(),"[<Event 1: 5>*, <Event 3: 5>]");
	EXPECT_EQ(S.remove(2),0);
	EXPECT_EQ(S.remove(1),1);
	EXPECT_EQ(S.str(),"[<Event 3: 5>*]");
}	
//-------------------------------------------------------------------------

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
