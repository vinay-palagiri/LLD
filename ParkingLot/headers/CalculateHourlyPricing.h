#pragma once

#include "ICalculatePricingStartegy.h"
#include <cmath>

class CalculateHourlyPricing : public ICalculatePricingStartegy
{
public:
    int calculatePrice(const Ticket *ticket, int timeTaken) override
    {
        int timeTakenInHours = std::ceil((double)timeTaken / (double)60);
        return 50 * timeTakenInHours * ticket->getParkingSpot()->getPrice();
    }
};