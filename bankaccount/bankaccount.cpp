#include "bankaccount.h"

BankAccount::BankAccount(string name,double balance)
{
    this->name=name;
    this->balance=balance;
}
BankAccount::withdraw(double amount)
{
    if(amount < 0|| this->balance-amount<0)
    {
        return 1;
    }
    this->balance=this->balance-amount;
    cout<<"当前jia余额"<<this->balance<<endl;

   return 0;
}
void BankAccount::deposit(double amount)
{
    this->balance+=amount;
    cout<<"当前"<<this->name<<"余额"<<this->balance<<endl;
}
string BankAccount::getName()
{
    return this->name;
}
double BankAccount::getBalance()
{
    return this->balance;
}
