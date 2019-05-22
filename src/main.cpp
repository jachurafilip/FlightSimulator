#include <Models/DummyModel.h>
#include "PlaneController.h"
#include <iostream>


int main(int argc, char** argv)
{
    Plane f(VelocityV(1,0,0));
    DummyModel m{Position()};
    PlaneController p(&f,&m);
    p.simulate();

    return 0;
}

