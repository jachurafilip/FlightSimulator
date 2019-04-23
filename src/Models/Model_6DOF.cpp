//
// Created by igor on 23.04.19.
//

#include "Model_6DOF.h"



void Model_6DOF::update(double dt) {
    plane_state newState;
    //TODO actual calculations
    state = newState;
    position = state.position;
}
