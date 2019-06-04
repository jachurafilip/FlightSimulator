//
// Created by igor on 03.06.19.
//

#include <Basic/Physics.h>
#include "Fuselage.h"
//ForceV drag = -0.5 * forward * p * area * parallelAirspeed * parallelAirspeed * getCoefficientOfLift(angleOfAttack);
std::pair<ForceV, MomentOfForce> Fuselage::getForces(const PlaneState &state) const {
    ForceV drag = Physics::calculateDrag(area, getRlativeAirspeed(state), dragCoefficient, Length(state.position.point.getY()));
    MomentOfForce momentOfDrag = (drag + drag).cross(LengthV(centerOfMass - state.centerOfMass));
    return std::pair<ForceV, MomentOfForce>();
}
