#pragma once

#include "IParkingStrategy.h"

class DefaultParkingStrategy : public IParkingStrategy
{
public:
    ParkingSpot *findSpot(const std::list<ParkingSpot *> &spots) override
    {
        for (auto *spot : spots)
        {
            if (spot->getIsEmpty())
                return spot;
        }
        return nullptr;
    }
};