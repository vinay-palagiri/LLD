#pragma once

#include "ParkingSpotManagerFactory.h"
#include "ParkingSpotManager.h"
#include "ICalculatePricingStartegy.h"

class ExitGate
{
public:
    ExitGate();
    int calculatePrice(const Ticket *ticket, int timeTaken) const;
    void setPricingStrategy(ICalculatePricingStartegy *pricingStrategy) { m_pricingStrategy = pricingStrategy; }
    void updateParkingSpot(ParkingSpot *spot) const;

    ParkingSpotManager *getParkingSpotManager(VehicleType type) const;
    bool makePayment(int price) const;
    void deleteTicket(Ticket *ticket) const;

private:
    ICalculatePricingStartegy *m_pricingStrategy;
};