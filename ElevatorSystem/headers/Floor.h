#pragma once
#include "EvenOddExternalDispatcher.h"

class Floor
{
public:
    Floor();
    ~Floor();
    void pressButton(int destFloor, Direction dir);
    void setExternalDispatcher(ExternalDispatcher *obj);

private:
    static int id_counter;
    int m_id;
    ExternalDispatcher *m_dispatcher;
};