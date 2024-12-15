#include "../headers/Building.h"

Building::Building(int numFloors) : m_numFloors(numFloors)
{
    for (int i = 0; i < numFloors; i++)
    {
        m_floors.push_back(new Floor());
    }
}

Building::~Building()
{
    for (auto floor : m_floors)
        delete floor;
}