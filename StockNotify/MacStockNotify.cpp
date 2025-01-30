#include "MacStockNotify.h"
#include "IObserver.h"

MacStockNotify::MacStockNotify()
{
    m_productName = "Macbook";
    resetStock();
}

void MacStockNotify::notify()
{
    for(auto obj : m_observers){
        obj->update(m_productName);
    }
}

void MacStockNotify::addStock(int val){
    if(m_stock == 0){
        notify();
    }
    m_stock += val;
}