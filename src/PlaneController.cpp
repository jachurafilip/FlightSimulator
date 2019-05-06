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
    using namespace std::chrono_literals;
    using namespace std::chrono;


    time_point<system_clock> start = system_clock::now();
    while(true) {
        duration<double> dt = system_clock::now() - start;
        start = system_clock::now();

        model->update(dt.count());
        plane->pos = model->getCurrentPosition();

        plane->draw();
        std::this_thread::sleep_until(start + 1000ms/FPS);
    }

}


