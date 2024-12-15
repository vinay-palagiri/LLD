#pragma once

#include "ExternalDispatcher.h"

class EvenOddExternalDispatcher : public ExternalDispatcher
{
public:
    EvenOddExternalDispatcher();

    void submitExternalRequest(int destFloor, Direction dir) override;
};