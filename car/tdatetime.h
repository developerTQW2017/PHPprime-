#ifndef TDATETIME_H
#define TDATETIME_H
#include<iostream>
#include<ctime>
#include <string>
using namespace std;

class TDateTime
{
public:
    TDateTime();//使用给定的时间（默认的时间值为当前的系统时间）构造日期时间值
    TDateTime(const TDateTime &p);//使用一个日期时间对象构造新的日期时间对象
    int getyear();
    int getmonth();
    int getday();
    int gethour();
    int getminute();
    int getsecond();
     void printf();//输出函数
    TDateTime& operator=(const TDateTime&t);
    int operator-(const TDateTime &D1);//计算时间差
   string change_TDateTime();//类型转换函数，将日期时间对象转换为字符串对象
    friend ostream&operator<< (ostream&,TDateTime&);  //输出运算符

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char*ptr;
    time_t lp;
};


#endif // TDATETIME_H
