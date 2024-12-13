#ifndef _PARKINGSPOT4WHEELER_H
#define _PARKINGSPOT4WHEELER_H

#include "ParkingSpot.h"

class ParkingSpot4Wheeler : public ParkingSpot
{
public:
    ParkingSpot4Wheeler() : ParkingSpot(ParkingSpotType::FOUR_WHEELER) {}

    int getPrice() const override { return 2; }
};

#endif