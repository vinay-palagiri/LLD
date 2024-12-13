#pragma once

#include "Ticket.h"

class ICalculatePricingStartegy
{
public:
    virtual int calculatePrice(const Ticket *ticket, int timeTaken) = 0;
};