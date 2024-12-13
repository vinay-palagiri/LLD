#include "../headers/EntryGate.h"

EntryGate::EntryGate(ParkingSpotManager *spotManager2Wheeler, ParkingSpotManager *spotManager4Wheeler) : m_spotManager4Wheeler(spotManager4Wheeler),
                                                                                                         m_spotManager2Wheeler(spotManager2Wheeler)
{
}

ParkingSpot *EntryGate::findParkingSpot(VehicleType type) const
{
    auto spotManager = getParkingSpotManager(type);
    return spotManager->findParkingSpot();
}

bool EntryGate::updateParkingSpot(Vehicle *vehicle, ParkingSpot *spot) const
{
    spot->parkVehicle(vehicle);
    return true;
}

Ticket *EntryGate::generateTicket(Vehicle *vehicle, ParkingSpot *spot) const
{
    return new Ticket(spot, vehicle);
}

ParkingSpotManager *EntryGate::getParkingSpotManager(VehicleType type) const
{
    if (type == VehicleType::CAR)
        return m_spotManager4Wheeler;

    if (type == VehicleType::BIKE)
        return m_spotManager2Wheeler;

    return nullptr;
}
