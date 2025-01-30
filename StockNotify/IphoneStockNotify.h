#pragma once

#include "IStockNotify.h"

class IphoneStockNotify : public IStockNotify{
public:
    IphoneStockNotify();
    ~IphoneStockNotify() = default;
    void notify() override;
    void addStock(int val) override;
};