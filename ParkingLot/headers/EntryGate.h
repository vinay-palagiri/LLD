#pragma once

#include "ParkingSpot.h"
#include "ParkingSpotManager.h"
#include "ParkingSpotManagerFactory.h"
#include "Ticket.h"

class EntryGate
{
public:
    EntryGate(ParkingSpotManager *spotManager2Wheeler, ParkingSpotManager *spotManager4Wheeler);
    ParkingSpot *findParkingSpot(VehicleType type) const;
    bool updateParkingSpot(Vehicle *vehicle, ParkingSpot *spot) const;
    Ticket *generateTicket(Vehicle *vehicle, ParkingSpot *spot) const;
    const ParkingSpotManager *getParkingSpotManager4Wheeler() const { return m_spotManager4Wheeler; }
    const ParkingSpotManager *getParkingSpotManager2Wheeler() const { return m_spotManager2Wheeler; }
    ParkingSpotManager *getParkingSpotManager(VehicleType type) const;

private:
    ParkingSpotManager *m_spotManager4Wheeler;
    ParkingSpotManager *m_spotManager2Wheeler;
};