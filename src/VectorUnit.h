//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_VECTORUNIT_H
#define FLIGHTSIMULATOR_VECTORUNIT_H

#include "PhysicalUnit.h"
#include "Vector.h"

template <typename MKSUnit>
class VectorUnit: public PhysicalUnit<MKSUnit>{

public:
    explicit VectorUnit(const Vector &vector) : PhysicalUnit<MKSUnit>(vector.magnitude()), vector(vector) {}
    explicit VectorUnit(const long double magnitude) : PhysicalUnit<MKSUnit>(magnitude), vector(magnitude,0,0){}

private:
    Vector vector;
};

using VelocityV = VectorUnit<MKSUnit<1,0,-1>>;
using AccelerationV = VectorUnit<MKSUnit<1,0,-2>>;
using ForceV = VectorUnit<MKSUnit<1,1,-2>>;



#endif //FLIGHTSIMULATOR_VECTORUNIT_H
