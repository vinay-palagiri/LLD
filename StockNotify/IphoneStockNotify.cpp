#include "IphoneStockNotify.h"
#include "IObserver.h"

IphoneStockNotify::IphoneStockNotify()
{
    m_productName = "IPhone";
    resetStock();
}

void IphoneStockNotify::notify()
{
    for(auto obj : m_observers){
        obj->update(m_productName);
    }
}

void IphoneStockNotify::addStock(int val){
    if(m_stock == 0){
        notify();
    }
    m_stock += val;
}