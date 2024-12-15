#pragma once
#include <vector>
// #include "LiftContoller.h"

class LiftController;
class InternalDispatcher
{
public:
    InternalDispatcher();
    void submitInternalRequest(int destFloor, int liftId);

private:
    std::vector<LiftController *> m_liftControllers;
};