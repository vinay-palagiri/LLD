#ifndef _CAR_H
#define _CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(std::string vehicleNo) : Vehicle(vehicleNo, VehicleType::CAR) {}
};

#endif