#include "../headers/EvenOddExternalDispatcher.h"
#include "../headers/LiftCreator.h"

EvenOddExternalDispatcher::EvenOddExternalDispatcher()
{
    m_liftControllers = LiftCreator::liftControllers;
}

void EvenOddExternalDispatcher::submitExternalRequest(int destFloor, Direction dir)
{
    for (auto liftCont : LiftCreator::liftControllers)
    {
        int liftId = liftCont->getLift()->getId();

        if (liftId % 2 == 1 && destFloor % 2 == 1)
            liftCont->submitExternalRequest(destFloor, dir);
        else if (liftId % 2 == 0 && destFloor % 2 == 0)
            liftCont->submitExternalRequest(destFloor, dir);
    }
}