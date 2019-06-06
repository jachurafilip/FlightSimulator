//
// Created by igor on 22.05.19.
//

#include <Basic/Physics.h>
#include "Part.h"


void Part::update(Time dt, const PlaneState &state) {}

VelocityV Part::getRlativeAirspeed(const PlaneState &state) const {
    return state.velocity + state.angularVelocity.cross(LengthV(state.centerOfMass - centerOfDrag));
}


Part::Part(Mass mass, MomentOfInertia selfMomentOfInertia, Point centerOfMass, Point centerOfDrag) :
    mass(mass), selfMomentOfInertia(selfMomentOfInertia), centerOfMass(centerOfMass), centerOfDrag(centerOfDrag){
    momentOfInertia = Physics::steiner(selfMomentOfInertia, mass, centerOfMass, Point{0, 0, 0});
}

