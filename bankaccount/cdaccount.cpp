#include "cdaccount.h"

CDAccount::CDAccount(string name,double balance,double interest_rate=0.035,bool tiqian=1):BankAccount(name,balance)
{
    this->interest_rate=interest_rate;
    this->tiqian=tiqian;
}
CDAccount::withdraw(double amount)
{
    if(amount < 0|| this->balance-amount<0)
    {
        return 1;
    }
    if(tiqian)
    {
        this->balance+=this->balance*this->interest_rate*0.75;
        cout<<"当前"<<this->name<<"余额"<<this->balance<<endl;
    }else{
        this->balance+=this->balance*this->interest_rate;
        cout<<"当前"<<this->name<<"余额"<<this->balance<<endl;

    }
    return 0;
}
double CDAccount::getInterest()
{
    return this->interest_rate;
}
bool CDAccount::getTiqian()
{
    return this->tiqian;
}
