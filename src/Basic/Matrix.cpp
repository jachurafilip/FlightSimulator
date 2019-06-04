//
// Created by igor on 27.05.19.
//

#include "Matrix.h"
#include <stdexcept>

Matrix Matrix::zeros() {
    return Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

Matrix Matrix::identity() {
    return Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

Matrix Matrix::ones() {
    return Matrix(1, 1, 1, 1, 1, 1, 1, 1, 1);
}

void Matrix::set(int x, int y, double value) {
    if (x>2 or y>2) throw std::out_of_range("Index outside of matrix");
    data_[x*3+y] = value;
}

double Matrix::get(int x, int y) const{
    if (x>2 or y>2) throw std::out_of_range("Index outside of matrix");
    return data_[x*3+y];

}

Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result = Matrix::zeros();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.data_[3*i+j] += this->get(i, k) * other.get(k, j);
            }
        }
    }
}

Vector Matrix::operator*(const Vector &vector) const {
    return Vector(this->get(0, 0) * vector.getX() + this->get(0, 1) * vector.getY() + this->get(0, 2) * vector.getZ(),
                  this->get(1, 0) * vector.getX() + this->get(1, 1) * vector.getY() + this->get(1, 2) * vector.getZ(),
                  this->get(2, 0) * vector.getX() + this->get(2, 1) * vector.getY() + this->get(2, 2) * vector.getZ());
}

Matrix &Matrix::operator+=(const Matrix &other){
    for (int i = 0; i < 9; ++i) {
        data_[i]+=other.data_[i];
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    for (int i = 0; i < 9; ++i) {
        data_[i]-=other.data_[i];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result = *this;
    result += other;
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    Matrix result = *this;
    result -= other;
    return result;
}

Matrix Matrix::operator*=(double factor) {
    for (int i = 0; i < 9; ++i) {
        data_[i]*=factor;
    }
    return *this;
}

Matrix Matrix::operator*(double factor) const {
    Matrix result = *this;
    result *= factor;
    return result;
}

Matrix Matrix::inverse() const{
    double invDet = 1/det();
    return Matrix(minorDet(0, 0)*invDet,
                  minorDet(0, 1)*invDet,
                  minorDet(0, 2)*invDet,
                  minorDet(1, 0)*invDet,
                  minorDet(1, 1)*invDet,
                  minorDet(1, 2)*invDet,
                  minorDet(2, 0)*invDet,
                  minorDet(2, 1)*invDet,
                  minorDet(2, 2)*invDet);
}

double Matrix::det() const {
    return data_[0]*data_[4]*data_[8]
         + data_[1]*data_[5]*data_[6]
         + data_[2]*data_[3]*data_[7]
         - data_[0]*data_[5]*data_[7]
         - data_[1]*data_[3]*data_[8]
         - data_[2]*data_[4]*data_[6];
}

double Matrix::minorDet(int x, int y) const {
    if (x>2 or y>2) throw std::out_of_range("Index outside of matrix");
    int x1 = x == 0 ? 1 : 0;
    int x2 = x == 1 ? 2 : 1;
    int y1 = y == 0 ? 1 : 0;
    int y2 = y == 1 ? 2 : 1;
    return get(x1, y1) * get(x2, y2) - get(x2, y1)  * get(x1, y2);
}

