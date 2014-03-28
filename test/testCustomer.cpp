#include <gtest/gtest.h>
#include "../src/Customer.h"
#include <iostream>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(CustomerTest,EmptyConstructor){
    Customer c;
    EXPECT_EQ(0.0,c.time());
    EXPECT_EQ("",c.label());
}
// ---------------------------------------------------------------- //

// -------------------------- Test str ---------------------------- //
TEST(CustomerTest,Str){
    Customer c;
    EXPECT_EQ("<Customer : 0>",c.str());
}
// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
