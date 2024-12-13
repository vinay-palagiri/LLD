#include "../headers/ParkingSpot.h"

int ParkingSpot::id_counter = 1;

ParkingSpot::ParkingSpot(ParkingSpotType type) : m_isEmpty(true), m_id(id_counter), m_type(type), m_vehicle(nullptr)
{
    id_counter++;
}

void ParkingSpot::parkVehicle(Vehicle *vehicle)
{
    m_vehicle = vehicle;
    m_isEmpty = false;
}

void ParkingSpot::unParkVehicle()
{
    m_vehicle = nullptr;
    m_isEmpty = true;
}