//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_POINT_H
#define FLIGHTSIMULATOR_POINT_H

#include <memory>
#include <ostream>
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

    friend std::ostream &operator<<(std::ostream &os, const Point &point);

    double distance(const Point &other);

    Point& moveByVec(const Vector &vec);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    Point operator + (const Vector &vec);

    Vector operator - (const Point& other) const;

private:
    double x,y,z;

};


#endif //FLIGHTSIMULATOR_POINT_H
