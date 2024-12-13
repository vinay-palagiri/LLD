#pragma once

#include <list>
#include "ParkingSpot.h"

class IParkingStrategy
{
public:
    virtual ParkingSpot *findSpot(const std::list<ParkingSpot *> &spots) = 0;
};