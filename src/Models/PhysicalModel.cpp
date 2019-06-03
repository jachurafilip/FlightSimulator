//
// Created by filip on 19.04.19.
//

#include <iostream>
#include "PhysicalModel.h"

PhysicalModel::PhysicalModel(const Position &position) : position(position), logs(true) {}

const Position &PhysicalModel::getCurrentPosition() const {
    return position;
}

PhysicalModel::PhysicalModel() {
    position = Position();
    logs = true;

}

const Position &PhysicalModel::getPreviousPosition() const {
    return previousPosition;
}

void PhysicalModel::setThrottle(double amount) {

    throttle+=amount;

    if(throttle < 0)   throttle =0;
    if(throttle > 100) throttle = 100;
    std::cout<<"Throttle is at"<<throttle<<"%";


}

void PhysicalModel::setAilerons(double amount) {
    ailerons+=amount;
    if(ailerons < -100) ailerons = -100;
    if(ailerons > 100)  ailerons = 100;

}

void PhysicalModel::setElevators(double amount) {
    elevators+=amount;
    if(elevators < -100) elevators = -100;
    if(elevators > 100)  elevators = 100;

}

void PhysicalModel::Flaps() {
 flaps = !flaps;
}

void PhysicalModel::Logs() {
    logs = !logs;

}
