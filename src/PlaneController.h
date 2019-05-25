//
// Created by filip on 19.04.19.
//

#ifndef FLIGHTSIMULATOR_PLANECONTROLLER_H
#define FLIGHTSIMULATOR_PLANECONTROLLER_H

#include <memory>
#include "Plane.h"
#include "Models/PhysicalModel.h"

class PlaneController {
public:

    PlaneController(Plane *p,PhysicalModel *m):plane(p), model(m){
        previous = std::chrono::system_clock::now();
    };
    void simulate();
    void waitForUsersAction();
    std::unique_ptr<Plane> plane;
    std::unique_ptr<PhysicalModel> model;
    void moveAilerons(double value);
    void moveElevators(double value);
    void moveRudder(double value);
    void throttle(double value);

private:
    const int FPS = 30;
    std::chrono::time_point<std::chrono::system_clock> previous;


};


#endif //FLIGHTSIMULATOR_PLANECONTROLLER_H
