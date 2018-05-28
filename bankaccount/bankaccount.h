#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(string name,double balance);
    void deposit(double amount);    //存款
    virtual int withdraw(double amount);   //取款
    string getName();     //获取用户名
    double getBalance();      //获取操作金额
protected:
    string name;    //账户所有人姓名
    double balance;    //账户余额

};

#endif // BANKACCOUNT_H
