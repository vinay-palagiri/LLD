#pragma once
#include <string>
#include "IObserver.h"

class IStockNotify;
class EmailObserver : public IObserver{
public:
    EmailObserver(IStockNotify* obj, std::string email);
    ~EmailObserver() = default;
    void update(const std::string& prodName) override;

private:
    IStockNotify* m_observer;
    std::string m_email;
};