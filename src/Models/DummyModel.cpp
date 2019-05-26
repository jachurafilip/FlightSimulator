//
// Created by filip on 19.04.19.
//

#include <iostream>
#include <cmath>
#include "DummyModel.h"


void DummyModel::update(double dt) {
    previousPosition = position;

    v = v+(drag()/m)*Time(dt); // v = v0+a*t
    if(position.point.getZ()<=0 && (g+lift()/m).getValue().getZ()<0)
    {
        position.point.setZ(0);
        v.setValue(Vector{v.getValue().getX(),v.getValue().getY(),0});
    }
    else {
        v = v + (g + lift()/ m) * Time(dt);
    }



    if(v.getValue().getX()>VMax)
    {
        v = VelocityV(VMax,v.getValue().getY(),v.getValue().getZ());
    }
    if(v.getValue().getZ()>VMax/4)
    {
        v = VelocityV(v.getValue().getX(),v.getValue().getY(),VMax/4);
    }
    position.point.moveByVec(v.getValue()*dt);
    position.angles.roll+=ailerons*dt;
    position.angles.pitch+=elevators*dt;

    if(position.point.getZ()<0)
    {
        position.point.setZ(0);
    }

    if(position.point!=previousPosition.point)
    std::cout<<"Speed: "<<v.getValue().getX()<<","<<v.getValue().getZ()<<"m/s, altitude: "<<position.point.getZ()<<" meters, pitching angle: "<<position.angles.pitch<<std::endl;
}

DummyModel::DummyModel(const Position &position) : PhysicalModel(position) {}

ForceV DummyModel::weight() {
    return g*m;
}

Density DummyModel::airDensity() {
    return Density(1.225+-0.00006125*position.point.getZ());
}

double DummyModel::dragCoefficient() {
    if(!flaps)
        return 0.2;
    else
        return 1.2;
}

double DummyModel::liftCoefficient() {
    if ((0.5+0.1459*position.angles.pitch/180+(-0.004236)*position.angles.pitch/180*position.angles.pitch/180) < 0)
        return 0;
    return 1+0.1459*position.angles.pitch/180+(-0.004236)*position.angles.pitch/180*position.angles.pitch/180;
}

ForceV DummyModel::lift() {


    double angle = position.angles.pitch*M_PI/180;



    double liftValue = liftCoefficient()*airDensity().getMagnitude()*v.magnitude()*v.magnitude()*wingArea.getMagnitude()/2;

    return ForceV{0,0,cos(angle)*liftValue};


}

ForceV DummyModel::drag() {

    double angle = position.angles.pitch*M_PI/180;

    double dragValue = maxThrust.magnitude()*throttle/100;
    double dragResistanceValue = v.getValue().getX()*v.getValue().getX()*dragCoefficient()*airDensity().getMagnitude()*frontalArea.getMagnitude()/2 ;
    double drag = dragValue-dragResistanceValue;

    return ForceV{drag*cos(angle),0,drag*sin(angle)};
}


