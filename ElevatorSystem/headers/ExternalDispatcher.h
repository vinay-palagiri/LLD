#pragma once

#include <vector>
#include "LiftContoller.h"
class ExternalDispatcher
{
public:
    virtual void submitExternalRequest(int destFloor, Direction dir) = 0;

protected:
    std::vector<LiftController *> m_liftControllers;
};