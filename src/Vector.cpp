//
// Created by filip on 03.04.19.
//

#include <cmath>
#include "Vector.h"

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::getX() const {
    return x;
}

void Vector::setX(double x) {
    Vector::x = x;
}

double Vector::getY() const {
    return y;
}

void Vector::setY(double y) {
    Vector::y = y;
}

double Vector::getZ() const {
    return z;
}

void Vector::setZ(double z) {
    Vector::z = z;
}

bool Vector::operator==(const Vector &other) const {
    return x==other.x && y==other.y && z==other.z;
}


Vector Vector::operator+(const Vector &other) {
    return Vector(x+other.x,y+other.y,z+other.z);
}

Vector &Vector::operator+=(const Vector &other) {
    x+=other.x;
    y+=other.y;
    z+=other.z;
    return *this;
}

Vector Vector::operator-(const Vector &other) {
    return Vector(x-other.x,y-other.y,z-other.z);
}

Vector &Vector::operator-=(const Vector &other) {
    x-=other.x;
    y-=other.y;
    z-=other.z;
    return *this;
}

Vector Vector::operator-() {
    return Vector(-x, -y, -z);
}

double Vector::dot(const Vector &other) const {
    return x*other.x+y*other.y+z*other.z;
}

Vector Vector::cross(const Vector &other) {
    return Vector(y*other.z-z*other.y, z*other.x-x*other.z, x*other.y-y*other.x);
}

Vector Vector::operator*(double c) {
    return Vector(c*x, c*y, c*z);
}

Vector operator*(double c, const Vector &vec) {
    return Vector(c*vec.x, c*vec.y, c*vec.z);
}

Vector &Vector::operator*=(double c) {
    x*=c;
    y*=c;
    z*=c;
    return *this;
}

Vector Vector::operator/(double c) {
    return Vector(x/c, y/c, z/c);
}

Vector operator/(double c, const Vector &vec) {
    return Vector(vec.x/c, vec.y/c, vec.z/c);
}

Vector &Vector::operator/=(double c) {
    x/=c;
    y/=c;
    z/=c;
    return *this;
}

double Vector::magnitude() const {
    return sqrt(this->dot(*this));
}


void Vector::normalize() {
    *this/this->magnitude();

}
Vector unit(Vector v) {
    return v/v.magnitude();
}

double cosine(const Vector &v, const Vector &u) {
    return unit(u).dot(unit(v));
}



