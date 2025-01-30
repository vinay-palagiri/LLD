#include "IStockNotify.h"
#include "IphoneStockNotify.h"
#include "MacStockNotify.h"
#include "EmailObserver.h"
#include "IObserver.h"
#include "SmsObserver.h"
#include <iostream>

int main(){
    IStockNotify* iph = new IphoneStockNotify();
    IStockNotify* mac = new MacStockNotify();

    IObserver* e1 = new EmailObserver(iph, "abc@gmail.com");
    IObserver* s1 = new SmsObserver(iph, "phoneNumber1");

    std::cout << "Add Iphone stock\n";
    iph->addStock(10);

    IObserver* e2 = new EmailObserver(mac, "xyz@gmail.com");
    IObserver* s2 = new SmsObserver(mac, "phoneNumber2");

    std::cout << "Add Mac stock\n";
    mac->addStock(10);
    std::cout << "Reset Mac stock" << std::endl;
    mac->resetStock();
    std::cout <<"Add Mac stock 2\n";
    mac->addStock(100);

    delete iph;
    delete mac;
    delete e1;
    delete e2;
    delete s1;
    delete s2;
}