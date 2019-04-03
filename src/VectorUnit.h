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
    VectorUnit(const Vector &vector) : PhysicalUnit<MKSUnit>(vector.magnitude()), vector(vector) {}

private:
    Vector vector;
};


#endif //FLIGHTSIMULATOR_VECTORUNIT_H
