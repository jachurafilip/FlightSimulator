//
// Created by igor on 26.05.19.
//

#ifndef FLIGHTSIMULATOR_ENGINE_H
#define FLIGHTSIMULATOR_ENGINE_H


#include "Part.h"

class Engine : public Part {
    ForceV maxThrust;
public:
    std::pair<ForceV, MomentOfForce> getForces(const PlaneState &state) const override;
};


#endif //FLIGHTSIMULATOR_ENGINE_H
