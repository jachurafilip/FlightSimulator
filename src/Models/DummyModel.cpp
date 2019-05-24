//
// Created by filip on 19.04.19.
//

#include <iostream>
#include "DummyModel.h"
#include "../Basic/Point.h"

void DummyModel::update(Time dt) {
    position.point.moveByVec((VelocityV{1, 0, 0} * dt).getValue());
}

DummyModel::DummyModel(const Position &position) : PhysicalModel(position) {}
