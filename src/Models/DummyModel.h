//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_DUMMYMODEL_H
#define FLIGHTSIMULATOR_DUMMYMODEL_H


#include "PhysicalModel.h"
#include "Basic/ScalarUnit.cpp"
#include "Basic/VectorUnit.h"

class DummyModel: public PhysicalModel {
public:
    DummyModel(const Position &position);
    DummyModel() {}
    void update(double dt) override;



private:
    const Mass m{13000};

    const AccelerationV g{0,0,-9.81};
    double liftCoefficient();
    double dragCoefficient();
    double VMax = 200;
    const Area wingArea{37.25};
    const Area frontalArea{7};
    Density airDensity();
    VelocityV v{0,0,0};
    ForceV weight();
    const ForceV maxThrust{54000};
    ForceV lift();
    ForceV drag();

};


#endif //FLIGHTSIMULATOR_DUMMYMODEL_H
