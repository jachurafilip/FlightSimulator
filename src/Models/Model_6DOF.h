//
// Created by igor on 23.04.19.
//

#ifndef FLIGHTSIMULATOR_MODEL_6DOF_H
#define FLIGHTSIMULATOR_MODEL_6DOF_H


#include "PhysicalModel.h"
#include "PlaneState.h"
#include <memory>
#include <vector>
#include <Models/PlaneParts/Part.h>
#include <Basic/MatrixUnit.h>

class Model_6DOF : public PhysicalModel {
private:
    PlaneState state;
    std::vector<std::unique_ptr<Part>> parts;
public:
    void update(Time dt) override;
private:
    std::pair<ForceV, MomentOfForce> getForces() const;
    MomentOfInertia getMoments() const;
    Mass getMasses() const;
    Point getCenterOfMass() const;
};


#endif //FLIGHTSIMULATOR_MODEL_6DOF_H
