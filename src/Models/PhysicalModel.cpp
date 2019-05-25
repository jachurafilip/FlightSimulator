//
// Created by filip on 19.04.19.
//

#include "PhysicalModel.h"

PhysicalModel::PhysicalModel(const Position &position) : position(position) {}

const Position &PhysicalModel::getCurrentPosition() const {
    return position;
}

PhysicalModel::PhysicalModel() {
    position = Position();

}

const Position &PhysicalModel::getPreviousPosition() const {
    return previousPosition;
}