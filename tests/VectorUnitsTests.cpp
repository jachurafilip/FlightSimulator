#include <gtest/gtest.h>
#include "Vector.h"
#include "VectorUnit.h"
TEST(VectorUnitsTests, VectorsAddition)
{
    EXPECT_EQ(Vector(2,1,1)+Vector(3,2,4),Vector(5,3,5));
}

TEST(VectorUnitsTests, VectorAdditionAssigment)
{
    Vector v(1,1,1);
    v+=Vector(2,3,4);
    EXPECT_EQ(v,Vector(3,4,5));
}
TEST(VectorUnitsTests,VectorUnitsAddition)
{
    VelocityV v1(1,1,1);
    VelocityV v2(2,2,2);

    EXPECT_EQ(v1+v2, VelocityV(3,3,3));

}

TEST(VectorUnitsTests, VectorUnitsDot)
{
    LengthV x(2,1,0);
    ForceV f(5,3,0);

    EXPECT_EQ(f.dot(x),Energy(13.0));
}

TEST(VectorUnitsTests, VectorUnitsCross)
{
    LengthV x(2,1,0);
    ForceV y(5,3,2);

    EXPECT_EQ(x.cross(y),MomentOfForce(2,-4,1));
}

TEST(VectorUnitsTests, VectorCastedToScalar)
{
    ForceV f(3,4,0);
    Force s(5.0);

    EXPECT_EQ(static_cast<Force>(f),s);
}
