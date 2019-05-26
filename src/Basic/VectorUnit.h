//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_VECTORUNIT_H
#define FLIGHTSIMULATOR_VECTORUNIT_H

#include <ostream>
#include "Vector.h"
#include "ScalarUnit.h"
template <int M, int K, int S>
class VectorUnit{

public:
    VectorUnit(): value_(0,0,0){}
    explicit VectorUnit(Vector vector) : value_(std::move(vector)) {}
    explicit VectorUnit(const long double magnitude) : value_(magnitude,0,0){}
    VectorUnit(const long double x, const long double y, const long double z) : value_(x,y,z) {}

    const Vector &getValue() const {
        return value_;
    }

    void setValue(const Vector &value) {
        value_ = value;
    }

    bool operator==(const VectorUnit<M,K,S> &rhs) const {
        return value_ == rhs.value_;
    }

    bool operator!=(const VectorUnit<M,K,S> &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const VectorUnit<M,K,S> &rhs) const {
        return value_ < rhs.value_;
    }

    bool operator>(const VectorUnit<M,K,S> &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const VectorUnit<M,K,S> &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const VectorUnit<M,K,S> &rhs) const {
        return !(*this < rhs);
    }

    VectorUnit<M,K,S> operator+(const VectorUnit<M,K,S> &other) const
    {
        return VectorUnit<M,K,S>(value_+other.value_);
    }

    VectorUnit<M,K,S> operator+=(const VectorUnit<M,K,S> &other)
    {
        value_+=other.value_;
        return *this;
    }

    VectorUnit<M,K,S> operator-(const VectorUnit<M,K,S> &other) const
    {
        return VectorUnit<M, K, S>(value_-other.value_);
    }

    VectorUnit<M,K,S> operator-=(const VectorUnit<M,K,S> &other)
    {
        value_-=other.value_;
        return *this;
    }

    VectorUnit<M,K,S> operator-() const
    {
        return VectorUnit<M,K,S>(-value_);
    }

    VectorUnit<M,K,S> operator*(const long double rhs) const
    {
        return VectorUnit<M, K, S>(rhs*value_);
    }
    template<int M1, int K1, int S1>
    VectorUnit<M+M1, K+K1, S+S1> operator*(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return VectorUnit<M+M1, K+K1, S+S1>(value_*rhs.getMagnitude());
    }

    template<int M1, int K1, int S1>
    friend VectorUnit<M+M1, K+K1, S+S1> operator*(const ScalarUnit<M,K,S> &lhs, const VectorUnit<M1,K1,S1> &rhs)
    {
        return VectorUnit<M+M1, K+K1, S+S1>(rhs.magnitude()*lhs.getMagnitude());
    }

    friend VectorUnit<M,K,S> operator*(const long double rhs,const VectorUnit<M,K,S> &lhs)
    {
        return VectorUnit<M, K, S>(rhs*lhs);
    }

    VectorUnit<M,K,S>&operator*=(const long double rhs)
    {
        value_*=rhs;
        return *this;
    }



    VectorUnit<M,K,S> operator/(const long double rhs) const
    {
        return VectorUnit<M, K, S>(value_/rhs);
    }

    VectorUnit<M,K,S>&operator/=(const long double rhs)
    {
        value_/=rhs;
        return *this;
    }

    template<int M1, int K1, int S1>
    VectorUnit<M-M1, K-K1, S-S1> operator/(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return VectorUnit<M-M1, K-K1, S-S1>(value_/rhs.getMagnitude());
    }


    template<int M1, int K1, int S1>
    ScalarUnit<M+M1,K+K1,S+S1> dot(const VectorUnit<M1,K1,S1> &other) const {
        return ScalarUnit<M + M1, K + K1, S + S1>(value_.dot(other.getValue()));
    }

    template<int M1, int K1, int S1>
    VectorUnit<M+M1,K+K1,S+S1> cross(const VectorUnit<M1,K1,S1> &other) const {
        return VectorUnit<M + M1, K + K1, S + S1>(value_.cross(other.getValue()));
    }

    double magnitude() const {
        return value_.magnitude();
    }
    friend std::ostream &operator<<(std::ostream &os, const VectorUnit &unit) {
        os << "value_: " << unit.value_;
        return os;
    }
    explicit operator ScalarUnit<M,K,S>() const
    {
        return ScalarUnit<M,K,S>(value_.magnitude());
    }

private:
    Vector value_;



};

using LengthV = VectorUnit<1,0,0>;
using VelocityV = VectorUnit<1,0,-1>;
using AccelerationV = VectorUnit<1,0,-2>;
using ForceV = VectorUnit<1,1,-2>;
using MomentOfForce = VectorUnit<2,1,-2>;
using MomentOfInertia = VectorUnit<-2, -1, 0>; //TODO moment bezwładności nie jest wektorem tylko tensorem, trzeba będzie to naprawić
using AngularVelocity = VectorUnit<0, 0, -1>;
using AngularAcceleration = VectorUnit<0, 0, -2>;


#endif //FLIGHTSIMULATOR_VECTORUNIT_H
