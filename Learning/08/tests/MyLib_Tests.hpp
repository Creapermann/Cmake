#include <iostream>

#include "gtest/gtest.h"

#include "MyLib.hpp"


TEST(General, TimesTwo)
{
    MyTest mytest;
    EXPECT_EQ(mytest.times_two(4), 8);
    EXPECT_EQ(mytest.times_two(0), 0);
    EXPECT_EQ(mytest.times_two(-120), -240);
    EXPECT_EQ(mytest.times_two(19), 38);
}

TEST(General, PlusFor)
{
    MyTest mytest;
    EXPECT_EQ(mytest.plus_four(4), 8);
    EXPECT_EQ(mytest.plus_four(-4), 0);
    EXPECT_EQ(mytest.plus_four(0), 4);    
}

TEST(General, MinusOne)
{
    MyTest mytest;
    EXPECT_EQ(mytest.minus_one(4), 3);
    EXPECT_EQ(mytest.minus_one(-4), -5);
    EXPECT_EQ(mytest.minus_one(0), -1);    
}