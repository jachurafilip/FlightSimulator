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
public:
    explicit PhysicalModel(const Position &position);
    PhysicalModel();

    const Position &getCurrentPosition() const;
    virtual void update(double dt) = 0;

    const Position &getPreviousPosition() const;
    // dt is time step in seconds

};


#endif //FLIGHTSIMULATOR_PHYSICALMODEL_H

