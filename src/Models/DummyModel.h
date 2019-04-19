//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_DUMMYMODEL_H
#define FLIGHTSIMULATOR_DUMMYMODEL_H


#include "PhysicalModel.h"

class DummyModel: public PhysicalModel {
public:
    VelocityV getCurrentSpeed(const Plane &plane, const VelocityV &v0) override;

    Angles getCurrentAngles(const Plane &plane) override;

};


#endif //FLIGHTSIMULATOR_DUMMYMODEL_H
