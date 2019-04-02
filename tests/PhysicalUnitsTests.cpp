
#include <gtest/gtest.h>
#include <PhysicalUnit.h>

TEST(PhysicalValue,Equality)
{
    EXPECT_EQ(Force(1.0),Force(1.0));
}

TEST(PhysicalValue,Inequality)
{
    EXPECT_NE(Force(1.0),Force(2.0));
}

TEST(PhysicalValue, Greater)
{
    EXPECT_GT(Force(2.0),Force(1.0));
}


TEST(PhysicalValueTests, IsAbleToAddTwoValues)
{
    EXPECT_EQ(Acceleration(4.0),Acceleration(3.0)+Acceleration(1.0));
}

TEST(PhysicalValueTests, IsAbleToSubtractTwoValues)
{
    EXPECT_EQ(Acceleration(2.0),Acceleration(3.0)-Acceleration(1.0));
}

TEST(PhysicalValueTests, IsAbleToMultiplyTwoValues)
{
    EXPECT_EQ(Force(2.0)*Length(3.0),Energy (6.0));
}

TEST(PhysicalValueTests, IsAbleToDivideTwoValues)
{
    EXPECT_EQ(Energy(6.0)/Time(2.0),Power(3.0));
}

TEST(PhysicalValueTests, LiteralOperators)
{
    EXPECT_EQ(10.0_kg*5.0_ms2, 50.0_N);
}