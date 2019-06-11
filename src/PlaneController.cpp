//
// Created by filip on 19.04.19.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "PlaneController.h"
#include <chrono>
#include <thread>
#include <Models/DummyModel.h>
#include <iostream>

using namespace std::chrono_literals;
using namespace std::chrono;

void PlaneController::simulate()
{
        duration<double> dt = system_clock::now() - previous;
        auto next = system_clock::now();
        model->update(dt.count());

        std::this_thread::sleep_until(previous + 1000ms/FPS);
        previous = next;

}

void PlaneController::moveAilerons(double value) {
    model->setAilerons(value);
}

void PlaneController::moveElevators(double value) {
    model->setElevators(value);
}

void PlaneController::throttle(double value) {
    model->setThrottle(value);

}

void PlaneController::flaps() {
    model->Flaps();

}

void PlaneController::turnLogs() {
    model->Logs();

}


