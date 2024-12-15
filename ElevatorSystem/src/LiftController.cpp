#include "../headers/LiftContoller.h"

LiftController::LiftController(int floors) : m_lift(new Lift(floors))
{
}

void LiftController::submitExternalRequest(int destFloor, Direction dir)
{
    if (m_lift->getDirection() == Direction::UP)
    {
        if (dir == Direction::UP)
        {
            if (destFloor < m_lift->getCurrentFloor())
                m_waitingList.push(destFloor);
            else
                m_minUpHeap.push(destFloor);
        }
        else
            m_maxDownHeap.push(destFloor);
    }
    else
    {
        if (dir == Direction::DOWN)
        {
            if (destFloor > m_lift->getCurrentFloor())
                m_waitingList.push(destFloor);
            else
                m_maxDownHeap.push(destFloor);
        }
        else
            m_minUpHeap.push(destFloor);
    }
}

void LiftController::submitInternalRequest(int destFloor)
{
    if (m_lift->getDirection() == Direction::UP)
    {
        if (destFloor < m_lift->getCurrentFloor())
            m_waitingList.push(destFloor);
        else
            m_minUpHeap.push(destFloor);
    }
    else
    {
        if (destFloor > m_lift->getCurrentFloor())
            m_waitingList.push(destFloor);
        else
            m_maxDownHeap.push(destFloor);
    }
}

void LiftController::moveLift()
{
    while (!m_maxDownHeap.empty() || !m_minUpHeap.empty() || !m_waitingList.empty())
    {
        if (m_lift->getDirection() == Direction::UP)
        {
            // add downwards jobs waiting in the queue to downward max heap
            while (!m_waitingList.empty())
            {
                m_maxDownHeap.push(m_waitingList.front());
                m_waitingList.pop();
            }
            while (!m_minUpHeap.empty())
            {
                m_lift->move(m_minUpHeap.top(), Direction::UP);
                m_minUpHeap.pop();
            }

            // now get the lift to the top down dir
            if (!m_maxDownHeap.empty() && m_lift->getCurrentFloor() < m_maxDownHeap.top())
                m_lift->move(m_maxDownHeap.top(), Direction::UP);

            m_lift->setDirection(Direction::DOWN);
        }
        else
        {
            while (!m_waitingList.empty())
            {
                m_minUpHeap.push(m_waitingList.front());
                m_waitingList.pop();
            }
            while (!m_maxDownHeap.empty())
            {
                m_lift->move(m_maxDownHeap.top(), Direction::DOWN);
                m_maxDownHeap.pop();
            }

            if (!m_minUpHeap.empty() && m_lift->getCurrentFloor() > m_minUpHeap.top())
                m_lift->move(m_minUpHeap.top(), Direction::DOWN);

            m_lift->setDirection(Direction::UP);
        }
    }
}