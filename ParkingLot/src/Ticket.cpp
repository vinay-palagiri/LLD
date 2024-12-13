#include "../headers/Ticket.h"

Ticket::Ticket(ParkingSpot *spot, Vehicle *vehicle) : m_vehicle(vehicle), m_parkingSpot(spot)
{
}