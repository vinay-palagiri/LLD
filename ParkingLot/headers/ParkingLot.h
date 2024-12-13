#pragma once

#include "EntryGate.h"
#include "ExitGate.h"
#include <unordered_map>

class ParkingLot
{
public:
    ParkingLot(int nEntry, int nExit);
    ~ParkingLot();

    const EntryGate *getEntryGate(int ind) const;
    const ExitGate *getExitGate(int ind) const;

    void addParkingSpot2Wheeler(ParkingSpot *spot);
    void addParkingSpot4Wheeler(ParkingSpot *spot);

    void removeParkingSpot2Wheeler(ParkingSpot *spot);
    void removeParkingSpot4Wheeler(ParkingSpot *spot);
    void setPricingStrategyAtExitGate(int ind, ICalculatePricingStartegy *ps);
    void displayParkingSpots2Wheeler() { m_spotManager2Wheeler->displayParkingSpots(); }
    void displayParkingSpots4Wheeler() { m_spotManager4Wheeler->displayParkingSpots(); }

private:
    std::unordered_map<int, EntryGate *>
        m_mpEntryGates;
    std::unordered_map<int, ExitGate *> m_mpExitGates;
    ParkingSpotManager *m_spotManager4Wheeler;
    ParkingSpotManager *m_spotManager2Wheeler;
};