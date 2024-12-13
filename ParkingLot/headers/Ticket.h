#pragma once
#ifndef _TICKET_H_
#define _TICKET_H_

#include "Vehicle.h"
#include <chrono>
#include "ParkingSpot.h"

class Ticket
{
public:
    Ticket(ParkingSpot *spot, Vehicle *vehicle);
    inline ParkingSpot *getParkingSpot() const { return m_parkingSpot; }
    inline Vehicle *getVehicle() const { return m_vehicle; }

private:
    Vehicle *m_vehicle;
    ParkingSpot *m_parkingSpot;
    // std::chrono::high_resolution_clock::time_point m_startTime;
    int m_startTime;
};

#endif //_TICKET_H