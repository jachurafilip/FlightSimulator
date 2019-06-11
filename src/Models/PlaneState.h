//
// Created by igor on 22.05.19.
//

#ifndef FLIGHTSIMULATOR_PLANESTATE_H
#define FLIGHTSIMULATOR_PLANESTATE_H

struct PlaneState{
    Position position;
    VelocityV absoluteVelocity; // in ground frame of reference

    VelocityV velocity; // in plane frame of reference
    AngularMomentum angularMomentum;
    AngularVelocity angularVelocity;
    Point centerOfMass;
    double AileronsAngle = 0;
    double ElevatorsAngle = 0;
    double RudderAngle = 0;
    double throttleSeting = 0;

};

#endif //FLIGHTSIMULATOR_PLANESTATE_H
