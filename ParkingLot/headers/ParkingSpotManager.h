#ifndef _PARKINGSPOTMANAGER_H_
#define _PARKINGSPOTMANAGER_H_

#include <list>
#include "ParkingSpot.h"
#include "IParkingStrategy.h"

class ParkingSpotManager
{
public:
    ParkingSpotManager();
    ~ParkingSpotManager();

    void addParkingSpot(ParkingSpot *spot);
    void removeParkingSpot(ParkingSpot *spot);
    ParkingSpot *findParkingSpot() const;
    void displayParkingSpots() const;

private:
    std::list<ParkingSpot *> m_parkingspots;
    IParkingStrategy *m_parkingStrategy;
};

#endif