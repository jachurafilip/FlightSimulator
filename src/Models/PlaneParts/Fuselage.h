//
// Created by igor on 03.06.19.
//

#ifndef FLIGHTSIMULATOR_FUSELAGE_H
#define FLIGHTSIMULATOR_FUSELAGE_H


#include "Part.h"

class Fuselage : public Part{
private:
    Area area;
    double dragCoefficient;
public:
    std::pair<ForceV, MomentOfForce> getForces(const PlaneState &state) const override;
};


#endif //FLIGHTSIMULATOR_FUSELAGE_H
