#include "../headers/InternalButtons.h"
#include <iostream>

InternalButtons::InternalButtons(int floors) : m_internalDispacher(new InternalDispatcher()), m_maxButton(floors)
{
}

void InternalButtons::pressButton(int destFloor, int liftId)
{
    if (destFloor > m_maxButton)
        std::cout << "selected button is not in the available buttons\n";

    m_internalDispacher->submitInternalRequest(destFloor, liftId);
}
