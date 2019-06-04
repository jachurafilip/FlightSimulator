//
// Created by igor on 22.05.19.
//

#ifndef FLIGHTSIMULATOR_WING_H
#define FLIGHTSIMULATOR_WING_H

#include <Part.h>

class Wing : public Part{
public:
    Area area;
    VectorUnit<0, 0, 0> forward;
    VectorUnit<0, 0, 0> up; // direction of generated positive lift
    std::pair<ForceV, MomentOfForce> getForces(const PlaneState &state) const override;
    double getCoefficientOfLift(double angleOfAttack) const;
    double getCoefficientOfDrag(double angleOfAttack) const;
};


#endif //FLIGHTSIMULATOR_WING_H
