//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_POINT_H
#define FLIGHTSIMULATOR_POINT_H

#include <memory>
#include "Vector.h"

class Point {
public:
    Point() = default;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    double distance(const Point &other);

    void moveByVec(const Vector &vec);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

private:
    double x,y,z;

};


#endif //FLIGHTSIMULATOR_POINT_H
