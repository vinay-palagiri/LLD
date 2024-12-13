#ifndef _PARKINGSPOT2WHEELER_H
#define _PARKINGSPOT2WHEELER_H

#include "ParkingSpot.h"

class ParkingSpot2Wheeler : public ParkingSpot
{
public:
    ParkingSpot2Wheeler() : ParkingSpot(ParkingSpotType::TWO_WHEELER) {}

    int getPrice() const override { return 1; }
};

#endif