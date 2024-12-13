#include "../headers/ParkingLot.h"

ParkingLot::ParkingLot(int nEntry, int nExit)
{
    m_spotManager2Wheeler = new ParkingSpotManager2Wheeler();
    m_spotManager4Wheeler = new ParkingSpotManager4Wheeler();
    for (int i = 0; i < nEntry; i++)
        m_mpEntryGates.insert({i + 1, new EntryGate(m_spotManager2Wheeler, m_spotManager4Wheeler)});

    for (int i = 0; i < nExit; i++)
        m_mpExitGates.insert({i + 1, new ExitGate()});
}

ParkingLot::~ParkingLot()
{
    delete m_spotManager2Wheeler;
    delete m_spotManager4Wheeler;

    for (auto it : m_mpEntryGates)
        delete it.second;

    for (auto it : m_mpExitGates)
        delete it.second;
}

const EntryGate *ParkingLot::getEntryGate(int ind) const
{
    auto it = m_mpEntryGates.find(ind);
    return it->second;
}

const ExitGate *ParkingLot::getExitGate(int ind) const
{
    auto it = m_mpExitGates.find(ind);
    return it->second;
}

void ParkingLot::addParkingSpot2Wheeler(ParkingSpot *spot)
{
    m_spotManager2Wheeler->addParkingSpot(spot);
}

void ParkingLot::addParkingSpot4Wheeler(ParkingSpot *spot)
{
    m_spotManager4Wheeler->addParkingSpot(spot);
}

void ParkingLot::removeParkingSpot2Wheeler(ParkingSpot *spot)
{
    m_spotManager2Wheeler->removeParkingSpot(spot);
}

void ParkingLot::removeParkingSpot4Wheeler(ParkingSpot *spot)
{
    m_spotManager4Wheeler->removeParkingSpot(spot);
}

void ParkingLot::setPricingStrategyAtExitGate(int ind, ICalculatePricingStartegy *ps)
{
    m_mpExitGates.find(ind)->second->setPricingStrategy(ps);
}
