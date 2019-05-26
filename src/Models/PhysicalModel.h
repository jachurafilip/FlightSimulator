//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALMODEL_H
#define FLIGHTSIMULATOR_PHYSICALMODEL_H


#include <chrono>
#include "../Basic/VectorUnit.h"
#include "../Plane.h"

class PhysicalModel {
protected:
    Position position;
    Position previousPosition;
    double throttle; // range [0,100]
    double ailerons; //range [-100,100] (-100 is left aileron up - plane rolling left)
    double elevators; //range [-100,100] (-100 is elevator down - plane pitching down)
public:
    explicit PhysicalModel(const Position &position);
    PhysicalModel();

    const Position &getCurrentPosition() const;
    virtual void update(double dt) = 0;

    const Position &getPreviousPosition() const;
    // dt is time step in seconds

    void setThrottle(double amount);
    void setAilerons(double amount);
    void setElevators(double amount);


};


#endif //FLIGHTSIMULATOR_PHYSICALMODEL_H

