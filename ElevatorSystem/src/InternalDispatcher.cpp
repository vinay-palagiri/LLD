#include "../headers/InternalDispatcher.h"
#include "../headers/LiftCreator.h"

InternalDispatcher::InternalDispatcher()
{
    m_liftControllers = LiftCreator::liftControllers;
}

void InternalDispatcher::submitInternalRequest(int destFloor, int liftId)
{
    LiftCreator::liftControllers[liftId - 1]->submitInternalRequest(destFloor);
}
