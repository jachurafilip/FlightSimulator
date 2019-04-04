//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_VECTORUNIT_H
#define FLIGHTSIMULATOR_VECTORUNIT_H

#include "Vector.h"
#include "ScalarUnit.h"
template <int M, int K, int S>
class VectorUnit{

public:
    explicit VectorUnit(Vector vector) : value_(std::move(vector)) {}
    explicit VectorUnit(const long double magnitude) : value_(magnitude,0,0){}
    VectorUnit(const long double x, const long double y, const long double z) : value_(x,y,z) {}

    const Vector &getValue() const {
        return value_;
    }

    void setValue(const Vector &value) {
        value_ = value;
    }

    bool operator==(const VectorUnit &rhs) const {
        return value_ == rhs.value_;
    }

    bool operator!=(const VectorUnit &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const VectorUnit &rhs) const {
        return value_ < rhs.value_;
    }

    bool operator>(const VectorUnit &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const VectorUnit &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const VectorUnit &rhs) const {
        return !(*this < rhs);
    }

    VectorUnit<M,K,S> operator+(const VectorUnit<M,K,S> &other)
    {
        return VectorUnit<M,K,S>(value_+other.value_);
    }
    VectorUnit<M,K,S> operator-(const VectorUnit<M,K,S> &other) {
        return VectorUnit<M, K, S>(value_-other.value_);
    }
    VectorUnit<M,K,S> operator-()
    {
        return VectorUnit<M,K,S>(-value_);
    }

    VectorUnit<M,K,S> operator*(const long double rhs) {
        return VectorUnit<M, K, S>(rhs*value_);
    }

    friend VectorUnit<M,K,S> operator*(const VectorUnit<M,K,S> &lhs, const long double rhs) {
        return VectorUnit<M, K, S>(rhs*lhs);
    }

    VectorUnit<M,K,S>&operator*=(const long double rhs) {
        value_*=rhs;
        return *this;
    }

    VectorUnit<M,K,S> operator/(const long double rhs) {
        return VectorUnit<M, K, S>(value_/rhs);
    }

    VectorUnit<M,K,S>&operator/=(const long double rhs) {
        value_/=rhs;
        return *this;
    }


    template<int M1, int K1, int S1>
    ScalarUnit<M+M1,K+K1,S+S1> dot(const VectorUnit<M1,K1,S1> &other) {
        return ScalarUnit<M + M1, K + K1, S + S1>(value_.dot(other.value_));
    }

    template<int M1, int K1, int S1>
    VectorUnit<M+M1,K+K1,S+S1> cross(const VectorUnit<M1,K1,S1> &other) {
        return VectorUnit<M + M1, K + K1, S + S1>(value_.cross(other.value_));
    }

    double magnitude() const {
        return value_.magnitude();
    }


private:
    Vector value_;


};

using VelocityV = VectorUnit<1,0,-1>;
using AccelerationV = VectorUnit<1,0,-2>;
using ForceV = VectorUnit<1,1,-2>;



#endif //FLIGHTSIMULATOR_VECTORUNIT_H
