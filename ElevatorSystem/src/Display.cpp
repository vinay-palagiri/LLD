#include "../headers/Display.h"
#include <iostream>

void Display::setDisplay(int floor, Direction dir)
{
    m_floor = floor;
    m_dir = dir;
}

void Display::showDisplay()
{
    std::cout << m_floor << std::endl;
    if (m_dir == Direction::UP)
        std::cout << "UP" << std::endl;
    else
        std::cout << "DOWN" << std::endl;
}