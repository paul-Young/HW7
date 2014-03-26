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
// ---------------------------------------------------------------- //
// -------------------------- Test str ---------------------------- //
TEST(RationalTest,Str){
    Event e;
    EXPECT_EQ("<Event 0: -1.0>",e.str());
}
// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
