//
// Created by igor on 22.05.19.
//

#include <Models/AtmosphereModel.h>
#include <Basic/Physics.h>
#include "Wing.h"
#include <math.h>

std::pair<ForceV, MomentOfForce> Wing::getForces(const PlaneState &state) const {
    VelocityV airspeed = getRlativeAirspeed(state);
    Velocity parallelAirspeed = Velocity(airspeed.dot(forward).getMagnitude());
    double angleOfAttack = atan((airspeed.dot(up) / airspeed.dot(forward)).getMagnitude());
    Density d = AtmosphereModel::getDensity(Length(state.position.point.getY()));
    ForceV drag = 0.5 * forward * d * area * parallelAirspeed * parallelAirspeed
            * getCoefficientOfDrag(angleOfAttack);
    ForceV lift = 0.5 * up * d * area * parallelAirspeed * parallelAirspeed
                        * getCoefficientOfLift(angleOfAttack);
    MomentOfForce momentOfDrag = (drag + lift).cross(LengthV(centerOfMass - state.centerOfMass));
    return std::make_pair(drag + lift, momentOfDrag);
}

double Wing::getCoefficientOfDrag(double angleOfAttack) const {
    return angleOfAttack / 3.14 + 0.01;
}

double Wing::getCoefficientOfLift(double angleOfAttack) const {
    return angleOfAttack;
}

