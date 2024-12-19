#pragma once

#include <vector>
#include "LiftContoller.h"
class ExternalDispatcher
{
public:
    virtual void submitExternalRequest(int destFloor, Direction dir) = 0;
    virtual ~ExternalDispatcher() = default;

protected:
    std::vector<LiftController *> m_liftControllers;
};