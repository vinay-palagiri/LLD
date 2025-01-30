#pragma once
#include <string>
#include "IObserver.h"

class IStockNotify;
class SmsObserver : public IObserver{
public:
    SmsObserver(IStockNotify* obj, std::string email);
    ~SmsObserver() = default;
    void update(const std::string& prodName) override;

private:
    IStockNotify* m_observer;
    std::string m_phone;
};