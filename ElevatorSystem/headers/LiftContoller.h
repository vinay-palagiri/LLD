#pragma once
#include "Lift.h"
#include <queue>

class LiftController
{
public:
    LiftController(int floors);
    void submitExternalRequest(int destFloor, Direction dir);
    void submitInternalRequest(int destFloor);
    void moveLift();

    const Lift *getLift() const { return m_lift; }

private:
    Lift *m_lift;
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_minUpHeap;
    std::priority_queue<int> m_maxDownHeap;
    std::queue<int> m_waitingList;
};