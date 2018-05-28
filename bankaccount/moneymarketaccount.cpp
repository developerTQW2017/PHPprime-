#include "moneymarketaccount.h"
#include <bankaccount.h>
MoneyMarketAccount::MoneyMarketAccount(string name,double balance,int times):BankAccount(name,balance)
{
this->times=times;
}
MoneyMarketAccount::withdraw(double amount)
{
    if(amount < 0|| this->balance-amount<0)
    {
        return 1;
    }
    if(this->times>=2)
    {
        if(this->balance-amount-1.5<0)
        {
            return 1;
        }else{

            this->balance=this->balance-amount-1.5;
            cout<<"当前"<<this->name<<"余额"<<this->balance<<endl;
            this->times++;
        return 0;
        }

    }else{
        this->balance=this->balance-amount;
        cout<<"当前"<<this->name<<"余额"<<this->balance<<endl;
        this->times++;
        return 0;
    }
}
MoneyMarketAccount::getTimes()
{
    return this->times;
}
