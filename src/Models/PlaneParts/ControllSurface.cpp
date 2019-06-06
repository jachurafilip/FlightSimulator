//
// Created by igor on 03.06.19.
//

#include <Models/AtmosphereModel.h>
#include <cmath>
#include "ControllSurface.h"

std::pair<ForceV, MomentOfForce> ControllSurface::getForces(const PlaneState &state) const {
    double deflection = 0.0;
    switch (type) {
        case aileron:
            deflection = maxDeflection * state.AileronsAngle;
            break;
        case elevator:
            deflection = maxDeflection * state.ElevatorsAngle;
        case rudder:
            deflection = maxDeflection * state.RudderAngle;
    }

    VelocityV airspeed = getRlativeAirspeed(state);
    Velocity parallelAirspeed = Velocity(airspeed.dot(forward).getMagnitude());
    double angleOfAttack = atan((airspeed.dot(up) / airspeed.dot(forward)).getMagnitude()) + deflection;
    Density d = AtmosphereModel::getDensity(Length(state.position.point.getY()));
    ForceV drag = 0.5 * forward * d * area * parallelAirspeed * parallelAirspeed
                  * getCoefficientOfDrag(angleOfAttack);
    ForceV lift = 0.5 * up * d * area * parallelAirspeed * parallelAirspeed
                  * getCoefficientOfLift(angleOfAttack);
    MomentOfForce momentOfDrag = (drag + lift).cross(LengthV(centerOfMass - state.centerOfMass));
    return std::make_pair(drag + lift, momentOfDrag);
}
