//
// Created by igor on 22.05.19.
//

#ifndef FLIGHTSIMULATOR_PLANESTATE_H
#define FLIGHTSIMULATOR_PLANESTATE_H

struct PlaneState{
    Position position;
    VelocityV absoluteVelocity;


    VelocityV velocity;

    double AileronsAngle = 0;
    double ElevatorsAngle = 0;
    double RudderAngle = 0;
    double throttleSeting = 0;
    //TODO add state variables;
};

#endif //FLIGHTSIMULATOR_PLANESTATE_H
