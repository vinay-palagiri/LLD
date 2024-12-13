#ifndef _PARKINGSPOT_H
#define _PARKINGSPOT_H

#include "Vehicle.h"

enum class ParkingSpotType
{
    FOUR_WHEELER,
    TWO_WHEELER,
};

class ParkingSpot
{
public:
    ParkingSpot(ParkingSpotType type);

    // getters
    bool getIsEmpty() const { return m_isEmpty; }
    int getId() const { return m_id; }
    virtual int getPrice() const = 0;
    ParkingSpotType getType() const { return m_type; }
    const Vehicle *getVehicle() const { return m_vehicle; }

    // logic
    void parkVehicle(Vehicle *vehicle);
    void unParkVehicle();

private:
    bool m_isEmpty;
    static int id_counter;
    int m_id;
    ParkingSpotType m_type;
    Vehicle *m_vehicle;
};

#endif