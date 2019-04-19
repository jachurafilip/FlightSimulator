//
// Created by filip on 03.04.19.
//

#include "ScalarUnit.h"

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