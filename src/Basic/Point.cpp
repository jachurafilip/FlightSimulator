//
// Created by filip on 03.04.19.
//

#include <cmath>
#include <memory>
#include "Point.h"

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

double Point::getZ() const {
    return z;
}

void Point::setZ(double z) {
    Point::z = z;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

double Point::distance(const Point &other) {
    return sqrt(pow(x-other.x,2.0)+pow(y-other.y,2.0)+pow(y-other.y,2.0));
}

void Point::moveByVec(const Vector &vec) {
    x+=vec.getX();
    y+=vec.getY();
    z+=vec.getZ();
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "x: " << point.x << " y: " << point.y << " z: " << point.z;
    return os;
}

