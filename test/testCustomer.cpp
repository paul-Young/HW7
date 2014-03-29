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

TEST(CustomerTest,Constructor){
    Customer c(1.0,"Bryan");
    EXPECT_EQ(1.0,c.time());
    EXPECT_EQ("Bryan",c.label());
}
// ---------------------------------------------------------------- //

// ----------------------- Test SetTime ----------------------- //
TEST(CustomerTest,SetIntTime){
    Customer c;
    c.setTime(2.0);
    EXPECT_EQ(0.0,c.time());
    EXPECT_EQ("",c.label());
}

TEST(CustomerTest,SetFloatTime){
    Customer c(1.5,"Bryan");
    EXPECT_EQ(1.5,c.time());
    EXPECT_EQ("Bryan",c.label());
}
// ---------------------------------------------------------------- //

// -------------------------- Test str ---------------------------- //
TEST(CustomerTest,DefaultStr){
    Customer c;
    EXPECT_EQ("<Customer : 0>",c.str());
}

TEST(CustomerTest,IntStr){
    Customer c(1.0,"Bryan");
    EXPECT_EQ(c.str(),"<Customer Bryan: 1>");
}

TEST(CustomerTest,FloatStr){
    Customer c(1.5,"Paul");
    EXPECT_EQ(c.str(),"<Customer Paul: 1.5>");
}
// ---------------------------------------------------------------- //
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
