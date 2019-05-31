//
// Created by igor on 22.05.19.
//

#include "Part.h"


void Part::update(Time dt, const PlaneState &state) {}

VelocityV Part::getRlativeAirspeed(PlaneState &state) const {
    return state.velocity + state.angularVelocity.cross(LengthV(Point{0, 0, 0} - centerOfDrag));
}
