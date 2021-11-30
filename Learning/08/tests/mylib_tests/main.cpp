#include <iostream>

#include "gtest/gtest.h"

#include "MyLib.hpp"


TEST(Full, MinusOne)
{
    MyTest t;
    
    EXPECT_EQ(t.minus_one(3), 2);    
}

TEST(Full, PlusFour)
{
    MyTest t;
    EXPECT_EQ(t.plus_four(4), 8);
}

TEST(Full, TimesTwo)
{
    MyTest t;
    EXPECT_EQ(t.times_two(6), 12);
}



int main()
{
    testing::InitGoogleTest();
    
    return RUN_ALL_TESTS();
}