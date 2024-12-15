#pragma once
#include <vector>
#include "Floor.h"

class Building
{
public:
    Building(int numFloors);
    ~Building();

    const std::vector<Floor *> &getFloors() const { return m_floors; }

private:
    int m_numFloors;
    std::vector<Floor *> m_floors;
};