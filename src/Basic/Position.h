//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_POSITION_H
#define FLIGHTSIMULATOR_POSITION_H

#include <ostream>
#include "Point.h"


struct Angles
{
    double pitch;
    double roll;
    double yaw;
};


struct Position
{
    Point point;
    Angles angles;

    friend std::ostream &operator<<(std::ostream &os, const Position &position) {
        os << "point: " << position.point;
        return os;
    }
};


#endif //FLIGHTSIMULATOR_POSITION_H
