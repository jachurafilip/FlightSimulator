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
class PhysicalValue {
private:
    long double magnitude_ {0.0};

public:
    constexpr explicit PhysicalValue(const long double magnitude) : magnitude_(magnitude) {}

    constexpr long double getMagnitude() const
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
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()==right.getMagnitude();
}

template<int M, int K, int S>
bool operator!=
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()!=right.getMagnitude();
}

template<int M, int K, int S>
bool operator>
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()>right.getMagnitude();
}

template<int M, int K, int S>
bool operator>=
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()>=right.getMagnitude();
}

template<int M, int K, int S>
bool operator<
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()<right.getMagnitude();
}

template<int M, int K, int S>
bool operator<=
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return left.getMagnitude()<=right.getMagnitude();
}

template<int M, int K, int S>
constexpr PhysicalValue<MKSUnit<M,K,S>>operator+
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalValue<MKSUnit<M,K,S>>(left.getMagnitude()+right.getMagnitude());
}

template<int M, int K, int S>
constexpr PhysicalValue<MKSUnit<M,K,S>>operator-
        (const PhysicalValue<MKSUnit<M,K,S>> &left, const PhysicalValue<MKSUnit<M,K,S>> &right) noexcept
{
    return PhysicalValue<MKSUnit<M,K,S>>(left.getMagnitude()-right.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
constexpr PhysicalValue<MKSUnit<M1+M2,K1+K2,S1+S2>>operator*
        (const PhysicalValue<MKSUnit<M1,K1,S1>> &left, const PhysicalValue<MKSUnit<M2,K2,S2>> &right)
{
    return PhysicalValue<MKSUnit<M1+M2,K1+K2,S1+S2>>(left.getMagnitude()*right.getMagnitude());
}

template<int M1, int K1, int S1, int M2, int K2, int S2>
constexpr PhysicalValue<MKSUnit<M1-M2,K1-K2,S1-S2>>operator/
        (const PhysicalValue<MKSUnit<M1,K1,S1>> &left, const PhysicalValue<MKSUnit<M2,K2,S2>> &right)
{
    return PhysicalValue<MKSUnit<M1-M2,K1-K2,S1-S2>>(left.getMagnitude()/right.getMagnitude());
}

using Quantity = PhysicalValue<MKSUnit<0,0,0>>;
constexpr Quantity operator""_Deg(long double magnitude)
{
    return Quantity(magnitude);
}
using Mass = PhysicalValue<MKSUnit<0,1,0>>;
constexpr Mass operator""_kg(long double magnitude)
{
    return Mass(magnitude);
}

using Length = PhysicalValue<MKSUnit<1,0,0>>;
constexpr Length operator""_m(long double magnitude)
{
    return Length(magnitude);
}

using Area = PhysicalValue<MKSUnit<2,0,0>>;
constexpr Area operator""_m2(long double magnitude)
{
    return Area(magnitude);
}

using Volume = PhysicalValue<MKSUnit<3,0,0>>;
constexpr Volume operator""_m3(long double magnitude)
{
    return Volume(magnitude);
}

using Time = PhysicalValue<MKSUnit<0,0,1>>;
constexpr Time operator""_s(long double magnitude)
{
    return Time(magnitude);
}

using Frequency = PhysicalValue<MKSUnit<0,0,-1>>;
constexpr Frequency operator""_Hz(long double magnitude)
{
    return Frequency(magnitude);
}

using Speed = PhysicalValue<MKSUnit<1,0,-1>>;
constexpr Speed operator""_ms(long double magnitude)
{
    return Speed(magnitude);
}

using Acceleration = PhysicalValue<MKSUnit<1,0,-2>>;
constexpr Acceleration operator""_ms2(long double magnitude)
{
    return Acceleration(magnitude);
}
using Force = PhysicalValue<MKSUnit<1,1,-2>>;
constexpr Force operator""_N(long double magnitude)
{
    return Force(magnitude);
}
using Pressure = PhysicalValue<MKSUnit<-1,1,-2>>;
constexpr Pressure operator""_Pa(long double magnitude)
{
    return Pressure(magnitude);
}

using Energy = PhysicalValue<MKSUnit<2,1,-2>>;
constexpr Energy operator""_J(long double magnitude)
{
    return Energy(magnitude);
}

using Power = PhysicalValue<MKSUnit<2,1,-3>>;
constexpr Power operator""_W(long double magnitude)
{
    return Power(magnitude);
}




#endif //FLIGHTSIMULATOR_PHYSICALVALUE_H
