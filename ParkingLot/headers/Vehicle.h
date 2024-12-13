#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>

enum class VehicleType
{
    CAR,
    BIKE,
};

class Vehicle
{
public:
    Vehicle(std::string vehicleNo, VehicleType type);

    // getters
    VehicleType getType() const { return m_type; }
    const std::string &getVehicleNo() const { return m_vehicleNo; }

private:
    std::string m_vehicleNo;
    VehicleType m_type;
};

#endif