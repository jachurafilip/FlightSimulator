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

using Mass = ScalarUnit<0,1,0>;
inline Mass operator""_kg(long double magnitude) noexcept
{
    return Mass(magnitude);
}

using Length = ScalarUnit<1,0,0>;
inline Length operator""_m(long double magnitude) noexcept
{
    return Length(magnitude);
}

using Area = ScalarUnit<2,0,0>;
inline Area operator""_m2(long double magnitude) noexcept
{
    return Area(magnitude);
}

using Volume = ScalarUnit<3,0,0>;
inline Volume operator""_m3(long double magnitude) noexcept
{
    return Volume(magnitude);
}

using Time = ScalarUnit<0,0,1>;
inline Time operator""_s(long double magnitude) noexcept
{
    return Time(magnitude);
}


using Frequency = ScalarUnit<0,0,-1>;
inline Frequency operator""_Hz(long double magnitude) noexcept
{
    return Frequency(magnitude);
}

using Velocity = ScalarUnit<1,0,-1>;
inline Velocity operator""_ms(long double magnitude) noexcept
{
    return Velocity(magnitude);
}

using Acceleration = ScalarUnit<1,0,-2>;
inline Acceleration operator""_ms2(long double magnitude) noexcept
{
    return Acceleration(magnitude);
}
using Force = ScalarUnit<1,1,-2>;
inline Force operator""_N(long double magnitude) noexcept
{
    return Force(magnitude);
}
using Pressure = ScalarUnit<-1,1,-2>;
inline Pressure operator""_Pa(long double magnitude) noexcept
{
    return Pressure(magnitude);
}

using Energy = ScalarUnit<2,1,-2>;
inline Energy operator""_J(long double magnitude) noexcept
{
    return Energy(magnitude);
}

using Power = ScalarUnit<2,1,-3>;
inline Power operator""_W(long double magnitude) noexcept
{
    return Power(magnitude);
}

using Density = ScalarUnit<-3, 1, 0>;

#endif //FLIGHTSIMULATOR_PHYSICALVALUE_H
