//
// Created by igor on 23.04.19.
//

#include "Model_6DOF.h"
#include <numeric>


void Model_6DOF::update(Time dt) {
    PlaneState newState{};
    ForceV forceV;
    MomentOfForce momentOfForce;
    std::tie(forceV, momentOfForce) = getForces();
    MomentOfInertia momentOfInertia = getMoments();
    Mass mass = getMasses();
    for (auto & part : parts){
        part->update(dt, state);
    }

    AccelerationV acceleration = forceV/mass;
    AngularAcceleration angularAcceleration = momentOfForce.cross(momentOfInertia);

    newState.velocity = state.velocity + acceleration * dt;

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
            MomentOfInertia{0, 0, 0},
            [](const auto& acc, const auto& elem){return acc + elem->momentOfInertia;});
}

Mass Model_6DOF::getMasses() const {
    return std::accumulate(parts.begin(), parts.end(),
                           Mass{0},
                           [](const auto& acc, const auto& elem){return acc + elem->mass;});
}
