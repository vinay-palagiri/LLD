#include "SmsObserver.h"
#include "IStockNotify.h"
#include <iostream>

SmsObserver::SmsObserver(IStockNotify *obj, std::string phone) : m_observer(obj), m_phone(phone)
{
    obj->addObserver(this);
}

void SmsObserver::update(const std::string& prodName)
{
    std::cout << "notification sent to phone : " << m_phone << " for product : " << prodName << std::endl;
}