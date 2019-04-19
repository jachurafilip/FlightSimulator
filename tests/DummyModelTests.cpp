
#include <gtest/gtest.h>
#include "Models/PhysicalModel.h"
#include "PlaneController.h"
#include "Models/DummyModel.h"

Plane f(VelocityV(1,0,0));
DummyModel m;


PlaneController p(&f,&m);

//todo testy