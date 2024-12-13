#include "../headers/ExitGate.h"
#include <iostream>

ExitGate::ExitGate() : m_pricingStrategy(nullptr)
{
}

int ExitGate::calculatePrice(const Ticket *ticket, int timeTaken) const
{
    // auto currTime = std::chrono::system_clock::now();
    if (!m_pricingStrategy)
    {
        std::cout << "select the pricing strategy before calculating price\n";
        return 0;
    }

    // auto start = ticket->getStartTime();
    // chrono::duration_cast<chrono::seconds>(end - start).count()

    return m_pricingStrategy->calculatePrice(ticket, timeTaken);
}

void ExitGate::updateParkingSpot(ParkingSpot *spot) const
{
    spot->unParkVehicle();
}

bool ExitGate::makePayment(int price) const
{
    std::cout << " Payment is done!!!\n";
    return true;
}

void ExitGate::deleteTicket(Ticket *ticket) const
{
    delete ticket;
}
