//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALVALUE_H
#define FLIGHTSIMULATOR_PHYSICALVALUE_H


template <int M, int K, int S>
class ScalarUnit {
protected:
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
};

template<int M, int K, int S>
bool operator==
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()==right.getMagnitude();
}

template<int M, int K, int S>
bool operator!=
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()!=right.getMagnitude();
}

template<int M, int K, int S>
bool operator>
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()>right.getMagnitude();
}

template<int M, int K, int S>
bool operator>=
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()>=right.getMagnitude();
}

template<int M, int K, int S>
bool operator<
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()<right.getMagnitude();
}

template<int M, int K, int S>
bool operator<=
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return left.getMagnitude()<=right.getMagnitude();
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator+
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return ScalarUnit<M,K,S>(left.getMagnitude()+right.getMagnitude());
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator-
        (const ScalarUnit<M,K,S> &left, const ScalarUnit<M,K,S> &right) noexcept
{
    return ScalarUnit<M,K,S>(left.getMagnitude()-right.getMagnitude());
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator-
        (const ScalarUnit<M,K,S> &value) noexcept
{
    return ScalarUnit<M,K,S>(-value.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
ScalarUnit<M1+M2,K1+K2,S1+S2>operator*
        (const ScalarUnit<M1,K1,S1> &left, const ScalarUnit<M2,K2,S2> &right) noexcept
{
    return ScalarUnit<M1+M2,K1+K2,S1+S2>(left.getMagnitude()*right.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
ScalarUnit<M1-M2,K1-K2,S1-S2>operator/
        (const ScalarUnit<M1,K1,S1> &left, const ScalarUnit<M2,K2,S2> &right) noexcept
{
    return ScalarUnit<M1-M2,K1-K2,S1-S2>(left.getMagnitude()/right.getMagnitude());
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator*
        (const long double multiplier, const ScalarUnit<M,K,S> &right) noexcept
{
    return ScalarUnit<M,K,S>(multiplier*right.getMagnitude());
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator*
        (const ScalarUnit<M,K,S> &left, const long double right) noexcept
{
    return ScalarUnit<M,K,S>(right*left.getMagnitude());
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator/
        (const ScalarUnit<M,K,S> &left, const long double right) noexcept
{
    return ScalarUnit<M,K,S>(left.getMagnitude()/right);
}

template<int M, int K, int S>
ScalarUnit<M,K,S>operator/
        (long double left, const ScalarUnit<M,K,S> &right) noexcept
{
    return ScalarUnit<-M,-K,-S>(left/right.getMagnitude());
}

using Quantity = ScalarUnit<0,0,0>;
Quantity operator""_Deg(long double magnitude) noexcept
{
    return Quantity(magnitude);
}
using Mass = ScalarUnit<0,1,0>;
Mass operator""_kg(long double magnitude) noexcept
{
    return Mass(magnitude);
}

using Length = ScalarUnit<1,0,0>;
Length operator""_m(long double magnitude) noexcept
{
    return Length(magnitude);
}

using Area = ScalarUnit<2,0,0>;
Area operator""_m2(long double magnitude) noexcept
{
    return Area(magnitude);
}

using Volume = ScalarUnit<3,0,0>;
Volume operator""_m3(long double magnitude) noexcept
{
    return Volume(magnitude);
}

using Time = ScalarUnit<0,0,1>;
Time operator""_s(long double magnitude) noexcept
{
    return Time(magnitude);
}

using Frequency = ScalarUnit<0,0,-1>;
Frequency operator""_Hz(long double magnitude) noexcept
{
    return Frequency(magnitude);
}

using Velocity = ScalarUnit<1,0,-1>;
Velocity operator""_ms(long double magnitude) noexcept
{
    return Velocity(magnitude);
}

using Acceleration = ScalarUnit<1,0,-2>;
Acceleration operator""_ms2(long double magnitude) noexcept
{
    return Acceleration(magnitude);
}
using Force = ScalarUnit<1,1,-2>;
Force operator""_N(long double magnitude) noexcept
{
    return Force(magnitude);
}
using Pressure = ScalarUnit<-1,1,-2>;
Pressure operator""_Pa(long double magnitude) noexcept
{
    return Pressure(magnitude);
}

using Energy = ScalarUnit<2,1,-2>;
Energy operator""_J(long double magnitude) noexcept
{
    return Energy(magnitude);
}

using Power = ScalarUnit<2,1,-3>;
Power operator""_W(long double magnitude) noexcept
{
    return Power(magnitude);
}


#endif //FLIGHTSIMULATOR_PHYSICALVALUE_H
