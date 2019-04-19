//
// Created by filip on 19.04.19.
//

#include "PlaneController.h"
#include <chrono>
#include <thread>
#include <Models/DummyModel.h>

void PlaneController::waitForUsersAction() {

}

void PlaneController::simulate()
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
    while(true) {
        auto newSpeed = model->getCurrentSpeed(*plane, plane->speed);
        auto newAngles = model->getCurrentAngles(*plane);

        plane->pos.point.moveByVec(newSpeed.getValue() / FPS);
        plane->pos.angles = newAngles;

        plane->draw();
        t+=std::chrono::milliseconds(33);
        std::this_thread::sleep_until(t);

    }

}


