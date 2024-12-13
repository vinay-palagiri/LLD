#include "../headers/ParkingSpotManager.h"
#include "../headers/DefaultParkingStrategy.h"
#include <iostream>

ParkingSpotManager::ParkingSpotManager()
{
    m_parkingStrategy = new DefaultParkingStrategy();
}

ParkingSpotManager::~ParkingSpotManager()
{
    delete m_parkingStrategy;
}

void ParkingSpotManager::addParkingSpot(ParkingSpot *spot)
{
    m_parkingspots.push_back(spot);
}

void ParkingSpotManager::removeParkingSpot(ParkingSpot *spot)
{
    m_parkingspots.remove(spot);
}

ParkingSpot *ParkingSpotManager::findParkingSpot() const
{
    return m_parkingStrategy->findSpot(m_parkingspots);
}

void ParkingSpotManager::displayParkingSpots() const
{
    for (auto *spot : m_parkingspots)
    {
        std::cout << "[ " << spot->getId() << " -> { Empty : " << spot->getIsEmpty() << ", Price : " << spot->getPrice() << " }]" << std::endl;
    }
}