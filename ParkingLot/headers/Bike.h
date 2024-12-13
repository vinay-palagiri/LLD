#ifndef _BIKE_H
#define _BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle
{
public:
    Bike(std::string vehicleNo) : Vehicle(vehicleNo, VehicleType::BIKE) {}
};

#endif