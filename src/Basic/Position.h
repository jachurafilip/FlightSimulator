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

    friend std::ostream &operator<<(std::ostream &os, const Angles &angles) {
        os << "pitch: " << angles.pitch << " roll: " << angles.roll << " yaw: " << angles.yaw;
        return os;
    }
};


struct Position
{
    Point point;
    Angles angles;

    friend std::ostream &operator<<(std::ostream &os, const Position &position) {
        os << "point: " << position.point<<", angles: "<<position.angles;
        return os;
    }
};


#endif //FLIGHTSIMULATOR_POSITION_H
