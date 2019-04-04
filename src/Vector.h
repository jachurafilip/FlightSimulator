//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_VECTOR_H
#define FLIGHTSIMULATOR_VECTOR_H

#include <memory>
#include <ostream>

class Vector {
public:
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    bool operator<(const Vector &rhs) const;

    bool operator>(const Vector &rhs) const;

    bool operator<=(const Vector &rhs) const;

    bool operator>=(const Vector &rhs) const;

    Vector operator+(const Vector &other) const;
    Vector& operator+=(const Vector &other);

    Vector operator-(const Vector &other);
    Vector& operator-=(const Vector &other);
    Vector operator-();

    double dot(const Vector &other) const ;
    Vector cross(const Vector &other);

    Vector operator*(double c);
    friend Vector operator*(double c, const Vector &vec);
    Vector&operator*=(double c);

    Vector operator/(double c);
    friend Vector operator/(double c, const Vector &vec);
    Vector&operator/=(double c);

    double magnitude() const;
    void normalize();
    friend Vector unit(Vector v);
    friend double cosine(const Vector &v, const Vector &u);

    friend std::ostream &operator<<(std::ostream &os, const Vector &vector);


private:

    double x,y,z;

};


#endif //FLIGHTSIMULATOR_VECTOR_H
