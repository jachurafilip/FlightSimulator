//
// Created by igor on 26.05.19.
//

#include "Engine.h"

std::pair<ForceV, MomentOfForce> Engine::getForces(const PlaneState &state) const {
    ForceV thrust = maxThrust * state.throttleSeting;
    MomentOfForce momentOfForce = thrust.cross(LengthV(centerOfMass - Point{0, 0, 0}));
    return std::make_pair(thrust, momentOfForce);
}
