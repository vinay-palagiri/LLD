#pragma once

#include "IStockNotify.h"

class MacStockNotify : public IStockNotify{
public:
    MacStockNotify();
    ~MacStockNotify() = default;
    void notify() override;
    void addStock(int val) override;
};