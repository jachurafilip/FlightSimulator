//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PLANECONTROLLER_H
#define FLIGHTSIMULATOR_PLANECONTROLLER_H

#include <memory>
#include "Models/PhysicalModel.h"

class PlaneController {
public:

    PlaneController(PhysicalModel *m): model(m){
        previous = std::chrono::system_clock::now();
    };
    void simulate();
    void moveAilerons(double value);
    void moveElevators(double value);
    void throttle(double value);
    void flaps();
    void turnLogs();

    std::unique_ptr<PhysicalModel> model;

private:
    const int FPS = 30;
    std::chrono::time_point<std::chrono::system_clock> previous;


};


#endif //FLIGHTSIMULATOR_PLANECONTROLLER_H
