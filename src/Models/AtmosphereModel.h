//
// Created by igor on 03.06.19.
//

#ifndef FLIGHTSIMULATOR_ATMOSPHEREMODEL_H
#define FLIGHTSIMULATOR_ATMOSPHEREMODEL_H

#include <Basic/ScalarUnit.h>

namespace AtmosphereModel{
    Density getDensity(Length altitude){
        return Density(1.2250 - altitude.getMagnitude() / 32000 * (1.2250 - 0.01322));
    }
}


#endif //FLIGHTSIMULATOR_ATMOSPHEREMODEL_H
