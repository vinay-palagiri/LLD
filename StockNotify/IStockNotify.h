#pragma once
#include <vector>
class IObserver;
class IStockNotify{
public:
    virtual ~IStockNotify() = default;
    virtual void notify() = 0;
    void addObserver(IObserver* obj){
        m_observers.push_back(obj);
    }
    virtual void addStock(int val) = 0;
    void resetStock(){ m_stock = 0;}

protected:
    std::vector<IObserver*> m_observers;
    std::string m_productName;
    int m_stock;
};