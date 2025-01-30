#include "EmailObserver.h"
#include "IStockNotify.h"
#include <iostream>

EmailObserver::EmailObserver(IStockNotify *obj, std::string email) : m_observer(obj), m_email(email)
{
    obj->addObserver(this);
}

void EmailObserver::update(const std::string& prodName)
{
    std::cout << "notification sent to email : " << m_email << " for product : " << prodName << std::endl;
}