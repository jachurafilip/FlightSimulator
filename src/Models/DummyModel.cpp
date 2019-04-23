//
// Created by filip on 19.04.19.
//

#include <iostream>
#include "DummyModel.h"


void DummyModel::update(double dt) {
    position.point.moveByVec(Vector{1, 0, 0} * dt);
}

DummyModel::DummyModel(const Position &position) : PhysicalModel(position) {}
