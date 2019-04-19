//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALMODEL_H
#define FLIGHTSIMULATOR_PHYSICALMODEL_H


#include "../Basic/VectorUnit.h"
#include "../Plane.h"

class PhysicalModel {

public:
    virtual VelocityV getCurrentSpeed(const Plane &plane, const VelocityV &v0) = 0;
    virtual Angles getCurrentAngles(const Plane &plane) = 0;

};


#endif //FLIGHTSIMULATOR_PHYSICALMODEL_H
