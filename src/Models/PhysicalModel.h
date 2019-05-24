//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALMODEL_H
#define FLIGHTSIMULATOR_PHYSICALMODEL_H


#include <chrono>
#include <Basic/VectorUnit.h>


#include <Plane.h>

class PhysicalModel {
protected:
    Position position;
public:
    explicit PhysicalModel(const Position &position);

    Position getCurrentPosition() const;
    virtual void update(Time dt) = 0; // dt is time step in seconds

};


#endif //FLIGHTSIMULATOR_PHYSICALMODEL_H
