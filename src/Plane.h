//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PLANE_H
#define FLIGHTSIMULATOR_PLANE_H


#include "Basic/VectorUnit.h"
#include "Basic/Position.h"

class Plane {
public:
    Plane() = default;
    explicit Plane(VelocityV v): speed(v){}
    virtual void draw();

    Position pos;
    VelocityV speed;
    double ailerons, elevators, rudder, throttle;
    bool wheels;
    //todo dopisać wszystkie potrzebne parametry samolotu ew. zrobić to w modelu


};


#endif //FLIGHTSIMULATOR_PLANE_H
