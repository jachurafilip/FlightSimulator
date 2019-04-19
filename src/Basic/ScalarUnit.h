//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALVALUE_H
#define FLIGHTSIMULATOR_PHYSICALVALUE_H


#include <ostream>

template <int M, int K, int S>
class ScalarUnit {
private:
    long double magnitude_ {0.0};

public:
    explicit ScalarUnit(const long double magnitude) : magnitude_(magnitude) {}

    long double getMagnitude() const
    {
        return magnitude_;
    }

    void setMagnitude_(long double magnitude_)
    {
        magnitude_ = magnitude_;
    }

    bool operator==(const ScalarUnit<M,K,S> &rhs) const {
        return magnitude_ == rhs.magnitude_;
    }

    bool operator!=(const ScalarUnit<M,K,S> &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const ScalarUnit<M,K,S> &rhs) const {
        return magnitude_ < rhs.magnitude_;
    }

    bool operator>(const ScalarUnit<M,K,S> &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const ScalarUnit<M,K,S> &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const ScalarUnit<M,K,S> &rhs) const {
        return !(*this < rhs);
    }

    ScalarUnit<M,K,S> operator+(const ScalarUnit<M,K,S> &other) const
    {
        return ScalarUnit<M,K,S>(magnitude_+other.getMagnitude());
    }
    ScalarUnit<M,K,S> operator-(const ScalarUnit<M,K,S> &other) const
    {
        return ScalarUnit<M, K, S>(magnitude_-other.getMagnitude());
    }
    ScalarUnit<M,K,S> operator-() const
    {
        return ScalarUnit<M,K,S>(-magnitude_);
    }

    ScalarUnit<M,K,S> operator* (const long double rhs) const
    {
        return ScalarUnit<M,K,S>(magnitude_*rhs);
    }
    friend ScalarUnit<M,K,S> operator*(const long double lhs, const ScalarUnit<M,K,S> &rhs)
    {
        return ScalarUnit<M,K,S>(rhs.magnitude_*lhs);
    }

    ScalarUnit<M,K,S>&operator*=(const long double rhs)
    {
        magnitude_*=rhs;
        return *this;
    }

    ScalarUnit<M,K,S> operator/ (const long double rhs) const
    {
        return ScalarUnit<M,K,S>(magnitude_/rhs);
    }
    friend ScalarUnit<M,K,S> operator/(const long double lhs, const ScalarUnit<M,K,S> &rhs)
    {
        return ScalarUnit<M,K,S>(rhs.magnitude_/lhs);
    }

    ScalarUnit<M,K,S>&operator/=(const long double rhs)
    {
        magnitude_/=rhs;
        return *this;
    }

    template <int M1, int K1, int S1>
    ScalarUnit<M+M1, K+K1,S+S1> operator*(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return ScalarUnit<M+M1, K+K1,S+S1>(rhs.getMagnitude()*magnitude_);
    }

    template <int M1, int K1, int S1>
    ScalarUnit<M-M1, K-K1,S-S1> operator/(const ScalarUnit<M1,K1,S1> &rhs) const
    {
        return ScalarUnit<M-M1, K-K1,S-S1>(magnitude_/rhs.getMagnitude());
    }


    friend std::ostream &operator<<(std::ostream &os, const ScalarUnit &unit) {
        os << "magnitude_: " << unit.magnitude_;
        return os;
    }
};



#endif //FLIGHTSIMULATOR_PHYSICALVALUE_H
