#include "../headers/Floor.h"
#include <iostream>

int Floor::id_counter = 1;
Floor::Floor() : m_id(id_counter), m_dispatcher(new EvenOddExternalDispatcher())
{
    id_counter++;
}

Floor::~Floor()
{
    delete m_dispatcher;
}

void Floor::pressButton(int destFloor, Direction dir)
{
    if (m_dispatcher == nullptr)
    {
        std::cout << "Set External dispatcher!!\n";
        return;
    }

    m_dispatcher->submitExternalRequest(destFloor, dir);
}

void Floor::setExternalDispatcher(ExternalDispatcher *obj)
{
    m_dispatcher = obj;
}
