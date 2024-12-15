#include "../headers/LiftCreator.h"

std::vector<LiftController *> LiftCreator::liftControllers;

void LiftCreator::createLifts(int numOfFloors, int numOfLifts)
{
    for (int i = 0; i < numOfLifts; i++)
    {
        liftControllers.push_back(new LiftController(numOfFloors));
    }
}
