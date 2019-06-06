//
// Created by filip on 19.04.19.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
        waitForUsersAction();
        start = system_clock::now();
        model->update(Time(1.0/FPS));
        plane->pos = model->getCurrentPosition();

        plane->draw();
        std::this_thread::sleep_until(start + 1000ms/FPS);
    }

}

void PlaneController::turnLogs() {
    model->Logs();

}


