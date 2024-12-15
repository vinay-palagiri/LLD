#include "../headers/Lift.h"
#include <iostream>
int Lift::id_counter = 1;
Lift::Lift(int floors) : m_id(id_counter), m_currentFloor(0), m_numberOfFloors(floors), m_dir(Direction::UP),
                         m_status(LiftStatus::IDLE), m_display(new Display()), m_internalButtons(new InternalButtons(floors))
{
    id_counter++;
}

Lift::~Lift()
{
    delete m_display;
    delete m_internalButtons;
}

void Lift::setDisplay()
{
    m_display->setDisplay(m_currentFloor, m_dir);
}

void Lift::pressButton(int destFloor, int liftId)
{
    m_internalButtons->pressButton(destFloor, liftId);
}

void Lift::showDisplay()
{
    m_display->showDisplay();
}

bool Lift::move(int destFloor, Direction dir)
{
    int startFloor = m_currentFloor;
    if (m_dir == Direction::UP)
    {
        for (int i = startFloor; i < destFloor; i++)
        {
            this->m_currentFloor = i;
            setDisplay();
            showDisplay();
            if (i == destFloor)
                return true;
        }
    }
    else
    {
        for (int i = startFloor; i >= destFloor; i--)
        {
            this->m_currentFloor = i;
            setDisplay();
            showDisplay();
            if (i == destFloor)
                return true;
        }
    }

    return false;
}
