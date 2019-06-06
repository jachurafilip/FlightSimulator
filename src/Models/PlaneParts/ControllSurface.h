//
// Created by igor on 03.06.19.
//

#ifndef FLIGHTSIMULATOR_CONTROLLSURFACE_H
#define FLIGHTSIMULATOR_CONTROLLSURFACE_H


#include "Wing.h"

enum ControllType{
    aileron,
    rudder,
    elevator
};

class ControllSurface : public Wing {
    double maxDeflection;
    ControllType type;
public:
    std::pair<ForceV, MomentOfForce> getForces(const PlaneState &state) const override;
};


#endif //FLIGHTSIMULATOR_CONTROLLSURFACE_H
