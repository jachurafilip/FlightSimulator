//
// Created by igor on 27.05.19.
//

#ifndef FLIGHTSIMULATOR_MATRIX_H
#define FLIGHTSIMULATOR_MATRIX_H


#include "Vector.h"

class Matrix {
public:
    double data_[9];

    Matrix(double a, double b, double c,
            double d, double e, double f,
           double g, double h, double i): data_{a, b, c, d, e, f, g, h, i}{};

    static Matrix zeros();
    static Matrix identity();
    static Matrix ones();

    void set(int x, int y, double value);
    double get(int x, int y) const ;
    Matrix operator*(const Matrix& other) const;
    Vector operator*(const Vector& vector) const;
    Matrix operator*=(double factor);
    Matrix operator*(double factor) const;
    Matrix& operator+= (const Matrix& other);
    Matrix operator+ (const Matrix& other) const;
    Matrix& operator-= (const Matrix& other);
    Matrix operator- (const Matrix& other) const;

};


#endif //FLIGHTSIMULATOR_MATRIX_H
