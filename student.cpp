#include "student.h"

student::student()
{

}
int student::setName(string name)
{
    this->stuName=name;
    return 0;
}
int student::setNum(string num)
{
    this->stuNum=num;
    return 0;
}
string student::getNum()
{
    return this->stuNum;
}
string student::getName()
{
    return this->stuName;
}
