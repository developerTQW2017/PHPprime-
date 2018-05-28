#include "tdatetime.h"
#include"string.h"
TDateTime::TDateTime()//使用给定的时间（默认的时间值为当前的系统时间）构造日期时间值
{
    struct tm ti ;
   lp =time(NULL) ;
   localtime_s(&ti,&lp) ;
    year = ti.tm_year+1900 ;
    month = ti.tm_mon+1 ;
    day = ti.tm_mday ;
    hour = ti.tm_hour ;
    minute = ti.tm_min ;
    second = ti.tm_sec ;

}
int TDateTime::getyear()
{
    return year;
}

int TDateTime::getmonth()
{
    return month;
}

int TDateTime::getday()
{
    return day;
}

int TDateTime::gethour()
{
    return hour;
}

int TDateTime::getminute()
{
    return minute;
}

int TDateTime::getsecond()
{
    return second;
}
int TDateTime::operator-(const TDateTime &D1)//计算时间差
    {
        return D1.lp-lp;
    }

TDateTime::TDateTime(const TDateTime &p)//使用一个日期时间对象构造新的日期时间对象
{
    year=p.year;
    month=p.month;
    day=p.day;
    hour=p.hour;
    minute=p.minute;
    second=p.second;
}
TDateTime&TDateTime::operator=(const TDateTime&s)
{

    if (this == &s)return *this;
    delete ptr;
    ptr = new char[strlen(s.ptr) + 1];
    strcpy(ptr, s.ptr);
    return *this;
}
string change_TDateTime()//类型转换函数，将日期时间对象转换为字符串对象
{
    std::string (year);
    std::string (month);
    std::string (day);
    std::string (hour);
    std:: string (minute);
    std::string (second);
    string s4;
    s4 = year +" /" + month + " /" + day + " " + hour + ":"+ minute +":" + second;
    return s4;

}

ostream&operator<<(ostream&output, TDateTime&dt)
{
    output << dt.year <<"/"<< dt.month <<"/"<<  dt .day<< " "<< dt.hour << ": "<< dt.minute <<":" << dt.second;
    return output;
}
void TDateTime::printf() //
{
     cout<<year<<"/"<<month<<"/"<<day<<"   "<<hour<<":"<<minute<<":"<<second<<endl;
}
