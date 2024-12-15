#pragma once
#include "EnumHelpers.h"

class Display
{
public:
    Display() : m_floor(0), m_dir(Direction::UP) {}

    // setters
    void setFloor(int floor) { m_floor = floor; }
    void setDirection(Direction dir) { m_dir = dir; }
    void setDisplay(int floor, Direction dir);

    // getters
    int getFloor() const { return m_floor; }
    Direction getDirection() const { return m_dir; }

    void showDisplay();

private:
    int m_floor;
    Direction m_dir;
};