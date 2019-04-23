//
// Created by filip on 19.04.19.
//

#include "PhysicalModel.h"

PhysicalModel::PhysicalModel(const Position &position) : position(position) {}

Position PhysicalModel::getCurrentPosition() const {
    return position;
}
