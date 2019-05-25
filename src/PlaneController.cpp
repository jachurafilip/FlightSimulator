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

void PlaneController::waitForUsersAction() {


}


void PlaneController::simulate()
{
    using namespace std::chrono_literals;
    using namespace std::chrono;


        duration<double> dt = system_clock::now() - previous;
        auto next = system_clock::now();
        model->update(dt.count());
        plane->pos = model->getCurrentPosition();

        plane->draw();
        std::this_thread::sleep_until(previous + 1000ms/FPS);
        previous = next;

}

void PlaneController::moveAilerons(double value) {
    std::cout<<"Ailerons moved by "<<value;

}

void PlaneController::moveElevators(double value) {

}


