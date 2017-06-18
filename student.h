#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class student
{
public:
    string stuNum;
    string stuName;
public:
    student();
    friend istream& operator>>(istream&is, student&st);
    friend ostream& operator<<(ostream&os, const student&st);
    int setName(string name);
    int setNum(string num);
    string getNum();
    string getName();
    friend class seat;
};

#endif // STUDENT_H
