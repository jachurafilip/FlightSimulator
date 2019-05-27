//
// Created by igor on 27.05.19.
//

#ifndef FLIGHTSIMULATOR_MATRIXUNIT_H
#define FLIGHTSIMULATOR_MATRIXUNIT_H

#include "Matrix.h"
#include "ScalarUnit.h"
#include "VectorUnit.h"

template <int M, int K, int S>
class MatrixUnit {
private:
    Matrix value_ = Matrix::zeros();
public:
    MatrixUnit(){};
    explicit MatrixUnit(Matrix matrix) : value_(std::move(matrix)){}

    const Matrix &getValue() const {
        return value_;
    }

    void setValue(const Matrix &value) {
        value_ = value;
    }

    MatrixUnit<M,K,S> operator+(const MatrixUnit<M,K,S> &other) const
    {
        return MatrixUnit<M,K,S>(value_+other.value_);
    }

    MatrixUnit<M,K,S> operator+=(const MatrixUnit<M,K,S> &other)
    {
        value_+=other.value_;
        return *this;
    }

    MatrixUnit<M,K,S> operator-(const MatrixUnit<M,K,S> &other) const
    {
        return MatrixUnit<M, K, S>(value_-other.value_);
    }

    MatrixUnit<M,K,S> operator-=(const MatrixUnit<M,K,S> &other)
    {
        value_-=other.value_;
        return *this;
    }


    MatrixUnit<M,K,S> operator*(const long double rhs) const
    {
        return MatrixUnit<M, K, S>(value_*rhs);
    }

    template<int M1, int K1, int S1>
    MatrixUnit<M+M1, K+K1, S+S1> operator*(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return MatrixUnit<M+M1, K+K1, S+S1>(value_*rhs.getMagnitude());
    }

    template<int M1, int K1, int S1>
    MatrixUnit<M+M1, K+K1, S+S1> operator*(const VectorUnit<M,K,S> &rhs)
    {
        return MatrixUnit<M+M1, K+K1, S+S1>(this->value_ * rhs.getValue());
    }

    MatrixUnit<M,K,S>&operator*=(const long double rhs)
    {
        value_*=rhs;
        return *this;
    }


    template<int M1, int K1, int S1>
    MatrixUnit<M-M1, K-K1, S-S1> operator/(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return MatrixUnit<M-M1, K-K1, S-S1>(value_/rhs.getMagnitude());
    }




};


#endif //FLIGHTSIMULATOR_MATRIXUNIT_H
