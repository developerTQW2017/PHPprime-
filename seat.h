#ifndef SEAT_H
#define SEAT_H
#include <student.h>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
class seat
{
public:
    seat();
    void insertStu(string num,string name,student *seats);
    void deleteStu(string num,student *seats);
    void displayStu(int x,int y,student *seats);
    void displayList(student *seats);
};

#endif // SEAT_H
