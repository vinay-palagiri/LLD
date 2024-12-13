#pragma once

#include "ParkingSpotManager.h"
#include "ParkingSpotManager2Wheeler.h"
#include "ParkingSpotManager4Wheeler.h"
#include "EntryGate.h"
#include "ExitGate.h"

class ParkingSpotManagerFactory
{
public:
    static ParkingSpotManager *createParkingSpotManager(VehicleType type)
    {
        if (type == VehicleType::CAR)
            return new ParkingSpotManager4Wheeler();

        if (type == VehicleType::BIKE)
            return new ParkingSpotManager2Wheeler();

        return nullptr;
    }
};