#include "./headers/ParkingLot.h"
#include "./headers/ParkingSpot4Wheeler.h"
#include "./headers/ParkingSpot2Wheeler.h"
#include "./headers/Bike.h"
#include "./headers/Car.h"
#include "./headers/CalculateHourlyPricing.h"
#include <iostream>

int main()
{

    ParkingLot *parkingLot = new ParkingLot(1, 1);
    auto entry = parkingLot->getEntryGate(1);
    auto exit = parkingLot->getExitGate(1);

    // create Parking Spots
    auto ps1 = new ParkingSpot2Wheeler();
    auto ps2 = new ParkingSpot2Wheeler();
    auto ps3 = new ParkingSpot2Wheeler();

    auto ps4 = new ParkingSpot4Wheeler();
    auto ps5 = new ParkingSpot4Wheeler();
    auto ps6 = new ParkingSpot4Wheeler();

    // add 2 wheeler parking spots to our parking lot
    parkingLot->addParkingSpot2Wheeler(ps1);
    parkingLot->addParkingSpot2Wheeler(ps2);
    parkingLot->addParkingSpot2Wheeler(ps3);

    // add 4 wheeler parking spots to our parking lot
    parkingLot->addParkingSpot4Wheeler(ps4);
    parkingLot->addParkingSpot4Wheeler(ps5);
    parkingLot->addParkingSpot4Wheeler(ps6);

    // display parking spots
    std::cout << "2 Wheeler parkings\n";
    parkingLot->displayParkingSpots2Wheeler();
    std::cout << " 4 wheeler parkings \n";
    parkingLot->displayParkingSpots4Wheeler();

    // add vehicles
    auto v1 = new Bike("xyz1");
    auto v2 = new Bike("xyz2");
    auto v3 = new Car("car1");
    auto v4 = new Car("car2");

    // vehicle 1 at entrance 1
    // get parking spot
    auto v1ps = entry->findParkingSpot(v1->getType());
    if (v1ps == nullptr)
        std::cout << "No parking is available\n";
    // generate ticket
    auto t1 = entry->generateTicket(v1, v1ps);

    // update parking spot
    entry->updateParkingSpot(v1, v1ps);

    // vehicle 1 at exit gate 1
    auto pricingStrategy = new CalculateHourlyPricing();
    parkingLot->setPricingStrategyAtExitGate(1, pricingStrategy);

    // calculate price
    int price = exit->calculatePrice(t1, 70);
    // make payment
    bool paymentStatus = exit->makePayment(price);

    // update parking spot
    exit->updateParkingSpot(t1->getParkingSpot());
    exit->deleteTicket(t1);

    delete parkingLot;
    delete ps1;
    delete ps2;
    delete ps3;
    delete ps4;
    delete ps5;
    delete ps6;

    delete v1;
    delete v2;
    delete v3;
    delete v4;

    return 0;
}