//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_DUMMYMODEL_H
#define FLIGHTSIMULATOR_DUMMYMODEL_H


#include "PhysicalModel.h"

class DummyModel: public PhysicalModel {
public:
    void update(double dt) override;
};


#endif //FLIGHTSIMULATOR_DUMMYMODEL_H
