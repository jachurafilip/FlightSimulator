//
// Created by filip on 03.04.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICALVALUE_H
#define FLIGHTSIMULATOR_PHYSICALVALUE_H


template <int M, int K, int S>
struct MKSUnit
{
    enum {
        meter = M, kilogram = K, second = S
    };
};

template <typename MKSUnit>
class PhysicalUnit {
private:
    long double magnitude_ {0.0};

public:
    explicit PhysicalUnit(const long double magnitude) : magnitude_(magnitude) {}

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
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()==right.getMagnitude();
}

template<int M, int K, int S>
bool operator!=
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()!=right.getMagnitude();
}

template<int M, int K, int S>
bool operator>
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()>right.getMagnitude();
}

template<int M, int K, int S>
bool operator>=
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()>=right.getMagnitude();
}

template<int M, int K, int S>
bool operator<
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()<right.getMagnitude();
}

template<int M, int K, int S>
bool operator<=
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()<=right.getMagnitude();
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator+
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(left.getMagnitude()+right.getMagnitude());
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator-
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(left.getMagnitude()-right.getMagnitude());
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator-
        (const PhysicalUnit<MKSUnit<M,K,S>> &value) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(-value.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
PhysicalUnit<MKSUnit<M1+M2,K1+K2,S1+S2>>operator*
        (const PhysicalUnit<MKSUnit<M1,K1,S1>> &left, const PhysicalUnit<MKSUnit<M2,K2,S2>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<M1+M2,K1+K2,S1+S2>>(left.getMagnitude()*right.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
PhysicalUnit<MKSUnit<M1-M2,K1-K2,S1-S2>>operator/
        (const PhysicalUnit<MKSUnit<M1,K1,S1>> &left, const PhysicalUnit<MKSUnit<M2,K2,S2>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<M1-M2,K1-K2,S1-S2>>(left.getMagnitude()/right.getMagnitude());
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator*
        (const long double multiplier, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(multiplier*right.getMagnitude());
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator*
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const long double right) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(right*left.getMagnitude());
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator/
        (const PhysicalUnit<MKSUnit<M,K,S>> &left, const long double right) noexcept
{
    return PhysicalUnit<MKSUnit<M,K,S>>(left.getMagnitude()/right);
}

template<int M, int K, int S>
PhysicalUnit<MKSUnit<M,K,S>>operator/
        (long double left, const PhysicalUnit<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalUnit<MKSUnit<-M,-K,-S>>(left/right.getMagnitude());
}

using Quantity = PhysicalUnit<MKSUnit<0,0,0>>;
Quantity operator""_Deg(long double magnitude) noexcept
{
    return Quantity(magnitude);
}
using Mass = PhysicalUnit<MKSUnit<0,1,0>>;
Mass operator""_kg(long double magnitude) noexcept
{
    return Mass(magnitude);
}

using Length = PhysicalUnit<MKSUnit<1,0,0>>;
Length operator""_m(long double magnitude) noexcept
{
    return Length(magnitude);
}

using Area = PhysicalUnit<MKSUnit<2,0,0>>;
Area operator""_m2(long double magnitude) noexcept
{
    return Area(magnitude);
}

using Volume = PhysicalUnit<MKSUnit<3,0,0>>;
Volume operator""_m3(long double magnitude) noexcept
{
    return Volume(magnitude);
}

using Time = PhysicalUnit<MKSUnit<0,0,1>>;
Time operator""_s(long double magnitude) noexcept
{
    return Time(magnitude);
}

using Frequency = PhysicalUnit<MKSUnit<0,0,-1>>;
Frequency operator""_Hz(long double magnitude) noexcept
{
    return Frequency(magnitude);
}

using Velocity = PhysicalUnit<MKSUnit<1,0,-1>>;
Velocity operator""_ms(long double magnitude) noexcept
{
    return Velocity(magnitude);
}

using Acceleration = PhysicalUnit<MKSUnit<1,0,-2>>;
Acceleration operator""_ms2(long double magnitude) noexcept
{
    return Acceleration(magnitude);
}
using Force = PhysicalUnit<MKSUnit<1,1,-2>>;
Force operator""_N(long double magnitude) noexcept
{
    return Force(magnitude);
}
using Pressure = PhysicalUnit<MKSUnit<-1,1,-2>>;
Pressure operator""_Pa(long double magnitude) noexcept
{
    return Pressure(magnitude);
}

using Energy = PhysicalUnit<MKSUnit<2,1,-2>>;
Energy operator""_J(long double magnitude) noexcept
{
    return Energy(magnitude);
}

using Power = PhysicalUnit<MKSUnit<2,1,-3>>;
Power operator""_W(long double magnitude) noexcept
{
    return Power(magnitude);
}


#endif //FLIGHTSIMULATOR_PHYSICALVALUE_H
