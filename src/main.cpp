#include "Models/DummyModel.h"
#include "PlaneController.h"

int main()
{
    Plane f(VelocityV(1,0,0));
    DummyModel m;


    PlaneController p(&f,&m);
    p.simulate();
    return 0;
}