//
// Created by igor on 02.06.19.
//

#ifndef FLIGHTSIMULATOR_PHYSICS_H
#define FLIGHTSIMULATOR_PHYSICS_H


#include <Models/AtmosphereModel.h>
#include "MatrixUnit.h"
#include "Point.h"

namespace Physics{
    inline int kronecker (int x, int y) { return x==y ? 1 : 0;}

    MomentOfInertia steiner(const MomentOfInertia& oldMoment, const Mass& mass, const Point& oldAxis, const Point& newAxis){
        Matrix result = Matrix::zeros();
        Vector distance = (newAxis - oldAxis);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.set(i, j, static_cast<double>(oldMoment.getValue().get(i, j) +
                                mass.getMagnitude() * (kronecker(i, j) * distance.magnitude() * distance.magnitude() -
                                distance[i]*distance[j])));
            }
        }
        return MomentOfInertia(result);
    }

    ForceV calculateDrag(AreaV areaV, VelocityV airspeed, double dragCoefficient, Length altitude){
        return ForceV(-0.5 * areaV.magnitude() * airspeed.magnitude() * airspeed.magnitude() *
            AtmosphereModel::getDensity(altitude).getMagnitude() * dragCoefficient * airspeed.getValue().getNorm());
    }

}


#endif //FLIGHTSIMULATOR_PHYSICS_H
