//
// Created by filip on 19.04.19.
//

#include <iostream>
#include "DummyModel.h"


void DummyModel::update(double dt) {
    previousPosition = position;
    position.point.moveByVec(Vector{1, 0, 0} * dt*throttle/100);
    position.angles.roll+=ailerons*dt;
    position.angles.pitch+=elevators*dt;
}

DummyModel::DummyModel(const Position &position) : PhysicalModel(position) {}

