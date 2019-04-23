//
// Created by igor on 23.04.19.
//

#ifndef FLIGHTSIMULATOR_MODEL_6DOF_H
#define FLIGHTSIMULATOR_MODEL_6DOF_H


#include "PhysicalModel.h"

struct plane_state{
    Position position;
    VelocityV velocity;

    double AileronsAngle = 0;
    double ElevatorsAngle = 0;
    double RudderAngle = 0;
    double throttleSeting = 0;
    //TODO add state variables;
};

class Model_6DOF : public PhysicalModel {
private:
    plane_state state;
public:
    void update(double dt) override;
};


#endif //FLIGHTSIMULATOR_MODEL_6DOF_H
