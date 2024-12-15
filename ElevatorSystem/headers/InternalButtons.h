#pragma once
#include "InternalDispatcher.h"
#include "EnumHelpers.h"

class InternalButtons
{
public:
    InternalButtons(int floors);
    void pressButton(int destFloor, int liftId);

private:
    InternalDispatcher *m_internalDispacher;
    int m_maxButton;
};