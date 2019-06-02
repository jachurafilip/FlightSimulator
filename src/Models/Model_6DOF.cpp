//
// Created by igor on 23.04.19.
//

#include "Model_6DOF.h"
#include <numeric>
#include <Basic/Physics.h>


void Model_6DOF::update(Time dt) {
    PlaneState newState{};
    ForceV forceV;
    MomentOfForce momentOfForce;
    std::tie(forceV, momentOfForce) = getForces();
    Mass mass = getMasses();
    Point centerOfMass = getCenterOfMass();
    MomentOfInertia momentOfInertia = Physics::steiner(getMoments(), mass, {0, 0, 0}, centerOfMass)
            ;
    for (auto & part : parts){
        part->update(dt, state);
    }

    AccelerationV acceleration = forceV/mass;

    newState.angularMomentum = state.angularMomentum + momentOfForce * dt;
    newState.velocity = state.velocity + acceleration * dt;

    newState.angularVelocity = momentOfInertia.inverse() * newState.angularMomentum;

    newState.position.point = state.position.point + (state.absoluteVelocity * dt).getValue();


    state = newState;
    position = state.position;
}

std::pair<ForceV, MomentOfForce> Model_6DOF::getForces() const {
    std::pair<ForceV, MomentOfForce> sum = std::make_pair(ForceV{0 ,0, 0}, MomentOfForce{0, 0, 0});
    for (const auto & part : parts){
        std::pair<ForceV, MomentOfForce> forces = part->getForces(state);
        sum.first += forces.first;
        sum.second += forces.second;
    }
    return sum;
}

MomentOfInertia Model_6DOF::getMoments() const {
    return std::accumulate(parts.begin(), parts.end(),
            MomentOfInertia{Matrix::zeros()},
            [](const auto& acc, const auto& elem){return acc + elem->momentOfInertia;});
}

Mass Model_6DOF::getMasses() const {
    return std::accumulate(parts.begin(), parts.end(),
                           Mass{0},
                           [](const auto& acc, const auto& elem){return acc + elem->mass;});
}

Point Model_6DOF::getCenterOfMass() const {
    VectorUnit<1, 0, 0> offset = std::accumulate(parts.begin(), parts.end(),
                           VectorUnit<1, 1, 0>{0, 0, 0},
                           [](const auto& acc, const auto& elem){return acc + elem->mass * elem->centerOfMass;}) / getMasses();
    return Point{0, 0, 0} + offset.getValue();
}
