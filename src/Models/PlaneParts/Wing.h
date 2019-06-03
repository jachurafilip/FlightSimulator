//
// Created by igor on 22.05.19.
//

#ifndef FLIGHTSIMULATOR_WING_H
#define FLIGHTSIMULATOR_WING_H

#include <Part.h>

class Wing : public Part{
public:
    Area area;
    LengthV forward;
    LengthV up; // direction of generated positive lift
    std::pair<ForceV, MomentOfForce> getForces(const PlaneState &state) const override;
    double getCoefficientOfLift(double angleOfAttack) const;
    double getCoefficientOfDrag(double angleOfAttack) const;
};


#endif //FLIGHTSIMULATOR_WING_H
