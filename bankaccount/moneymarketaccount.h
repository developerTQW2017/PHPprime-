#ifndef MONEYMARKETACCOUNT_H
#define MONEYMARKETACCOUNT_H
#include <bankaccount.h>

class MoneyMarketAccount:public BankAccount
{
public:
    MoneyMarketAccount(string name,double balance,int times);
    int withdraw(double amount);
    int getTimes();
private:
    int times;
};

#endif // MONEYMARKETACCOUNT_H
