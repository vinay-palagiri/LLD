#pragma once

#include "ICalculatePricingStartegy.h"
class CalculateMinutePricing : public ICalculatePricingStartegy
{
public:
    inline int calculatePrice(const Ticket *ticket, int timeTaken) override
    {
        return timeTaken * ticket->getParkingSpot()->getPrice();
    }
};