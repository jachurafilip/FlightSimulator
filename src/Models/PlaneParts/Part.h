//
// Created by igor on 22.05.19.
//

#ifndef FLIGHTSIMULATOR_PART_H
#define FLIGHTSIMULATOR_PART_H

#include <Basic/VectorUnit.h>
#include <Basic/ScalarUnit.h>
#include <Basic/Position.h>
#include <Basic/MatrixUnit.h>
#include "Models/PlaneState.h"


class Part {
public:
    Mass mass;
    MomentOfInertia momentOfInertia; //relative to plane origin
    MomentOfInertia selfMomentOfInertia; //relative to part CoM
    Point centerOfMass;
    Point centerOfDrag;
public:
    Part(Mass mass, MomentOfInertia selfMomentOfInertia, Point centerOfMass, Point centerOfDrag);
    virtual void update(Time dt, const PlaneState &state);
    VelocityV getRlativeAirspeed(const PlaneState &state) const;
    virtual std::pair<ForceV, MomentOfForce> getForces(const PlaneState& state)const=0;
};


#endif //FLIGHTSIMULATOR_PART_H
