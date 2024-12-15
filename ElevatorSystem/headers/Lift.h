#pragma once

#include "EnumHelpers.h"
#include "Display.h"
#include "InternalButtons.h"

class Lift
{
public:
    Lift(int floors);
    ~Lift();

    // setters
    void setDirection(Direction dir) { m_dir = dir; }
    void setLiftStatus(LiftStatus status) { m_status = status; }
    void setDisplay();

    // getters
    int getId() const { return m_id; }
    Direction getDirection() const { return m_dir; }
    LiftStatus getLiftStatus() const { return m_status; }
    int getCurrentFloor() const { return m_currentFloor; }
    void pressButton(int destFloor, int liftId);
    void showDisplay();

    // logic
    bool move(int destFloor, Direction dir);

private:
    static int id_counter;
    int m_id;
    int m_currentFloor;
    int m_numberOfFloors;
    Direction m_dir;
    LiftStatus m_status;
    Display *m_display;
    InternalButtons *m_internalButtons;
};