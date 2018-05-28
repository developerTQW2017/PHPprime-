#ifndef CDACCOUNT_H
#define CDACCOUNT_H
#include <bankaccount.h>

class CDAccount:public BankAccount
{
public:
    CDAccount(string name,double balance,double interest_rate,bool tiqian);
    int withdraw(double amount);
    double getInterest();
    bool getTiqian();
private:
    double interest_rate;
    bool tiqian;
};

#endif // CDACCOUNT_H
