#include <iostream>

#include "gtest/gtest.h"

TEST(idk, first)
{
    EXPECT_EQ(1, 1);
}


int main()
{
    testing::InitGoogleTest();
    
    return RUN_ALL_TESTS();
}