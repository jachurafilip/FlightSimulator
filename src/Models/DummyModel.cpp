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
        v = v + (g + lift() / m) * Time(dt);
    }



    if(v.getValue().getX()>VMax)
    {
        v = VelocityV(VMax,v.getValue().getY(),v.getValue().getZ());
    }
    position.point.moveByVec(v.getValue()*dt);
    position.angles.roll+=ailerons*dt;
    position.angles.pitch+=elevators*dt;

    if(position.point.getZ()<0)
    {
        position.point.setZ(0);
    }

    if(position.point!=previousPosition.point)
    std::cout<<"Speed: "<<v.magnitude()<<"m/s, altitude: "<<position.point.getZ()<<" meters"<<std::endl;
}

DummyModel::DummyModel(const Position &position) : PhysicalModel(position) {}

ForceV DummyModel::weight() {
    return g*m;
}

Density DummyModel::airDensity() {
    return Density(1.225+-0.00006125*position.point.getZ());
}

double DummyModel::dragCoefficient() {
    return 0.09+(1*abs(sin(position.angles.pitch*M_PI)/180));
}

double DummyModel::liftCoefficient() {
    return 0.5+0.1459*position.angles.pitch+(-0.004236)*position.angles.pitch*position.angles.pitch;
}

ForceV DummyModel::lift() {
    Vector directon = v.getValue();
    if(directon.magnitude()==0)
    {
        return ForceV{0,0,0};
    }
    directon = unit(directon);


    Vector perpendicular = Vector{-directon.getZ(),0,directon.getX()};

    double liftValue = liftCoefficient()*airDensity().getMagnitude()*v.magnitude()*v.magnitude()*wingArea.getMagnitude();

    return ForceV{perpendicular.getX()*liftValue,0,perpendicular.getZ()*liftValue};


}

ForceV DummyModel::drag() {
    Vector direction = v.getValue();
    if(direction.magnitude()==0)
        direction = Vector{1,0,0};
    else {
        direction = unit(direction);
    }

    double dragValue = maxThrust.magnitude()*throttle/100;
    double dragResistanceValue = v.magnitude()*v.magnitude()*dragCoefficient()*airDensity().getMagnitude()*frontalArea.getMagnitude()/2 ;
    double drag = dragValue-dragResistanceValue;

    return ForceV{drag*direction.getX(),0,drag*direction.getZ()};
}


