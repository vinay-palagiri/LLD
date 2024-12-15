#include "./headers/Building.h"
#include "./headers/LiftCreator.h"
#include <iostream>

int main()
{
    std::cout << "Creating building with 5 floors\n";
    auto building = new Building(5);

    std::cout << " creating 2 Lifts\n";
    LiftCreator::createLifts(5, 2);
    auto floors = building->getFloors();

    std::cout << "Pressing up button from 1 floor\n";
    floors[1]->pressButton(1, Direction::UP);
    LiftCreator::liftControllers[0]->moveLift();
    LiftCreator::liftControllers[1]->moveLift();

    std::cout << "Press internal button to 4\n";
    LiftCreator::liftControllers[0]->submitInternalRequest(4);
    LiftCreator::liftControllers[0]->moveLift();
    LiftCreator::liftControllers[1]->moveLift();

    floors[4]->pressButton(4, Direction::DOWN);
    LiftCreator::liftControllers[0]->moveLift();
    LiftCreator::liftControllers[1]->moveLift();

    LiftCreator::deleteLifts();
    delete building;
    return 0;
}