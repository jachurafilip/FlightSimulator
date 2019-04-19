//
// Created by filip on 19.04.19.
//

#include <iostream>
#include "DummyModel.h"

VelocityV DummyModel::getCurrentSpeed(const Plane &plane, const VelocityV &v0) {
    std::cout<<plane.pos;
    return v0;
}

Angles DummyModel::getCurrentAngles(const Plane &plane) {
    return plane.pos.angles;
}
