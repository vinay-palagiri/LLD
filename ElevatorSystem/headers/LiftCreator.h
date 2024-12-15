#pragma once
#include "LiftContoller.h"
#include <vector>

class LiftCreator
{
public:
    static std::vector<LiftController *> liftControllers;

    static void createLifts(int numOfFloors, int numOfLifts);

    static void deleteLifts()
    {
        for (auto lc : liftControllers)
            delete lc;
    }
};