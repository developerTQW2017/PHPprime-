#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <student.h>
#include <seat.h>
#include <fstream>
using namespace std;
istream& operator>>(istream&is, student&st)//ifstream是isream的子类，也能作为函数的参数
{
    is >> st.stuName;
    is>>st.stuNum;
    return is;
}

ostream& operator<<(ostream&os, const student&st)//ofstream是osream的子类，也能作为函数的参数
{
    os << st.stuName << " " << st.stuNum << endl;
    return os;
}
int fileExist(string filename)
{
    fstream _file;
        _file.open(filename,ios::in);
        if(!_file)
            return 1;
        return 0;
}
int main()
{
    seat seatExam;
    student seats[64];
    if(fileExist("Examination seat.txt"))
    {
        for(int i=0;i<64;i++)
        {
            seats[i].setNum("0");
        }
    }
while(1){
    ifstream fin("Examination seat.txt");
    for(int i=0;i<64;i++)
    {
        fin >> seats[i];
    }
        fin.close();
cout.flags(ios::left);
cout<<setw(10)<<" ";
cout<<setw(40)<<"1－设定考场座位"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"2－取消考场座位"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"3－显示某座位考生信息"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"4－查找学生座位"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"5－查看考场座位表"<<endl;
int mark;
cin>>mark;

if(mark==1)
{
    string num1;
    string name1;

    cout<<"请输入准考证号"<<endl;
    cin>>num1;
    cout<<"请输入姓名"<<endl;
    cin>>name1;
    seatExam.insertStu(num1,name1,seats);
}else if(mark==2){
    cout<<"请输入需要取消的学生的准考证号"<<endl;
    string num;
    cin>>num;
    seatExam.deleteStu(num,seats);

}else if(mark==3){
    int hang,lie;
    cout<<"请输入所需要查看的学生行号"<<endl;
    cin>>hang;
    cout<<"请输入所需要查看的学生列号"<<endl;
    cin>>lie;
    int si=(8*(hang-1)+lie-1);
    cout<<si;
    cout<<"考生:"<<seats[si].stuName<<"学号:"<<seats[si].stuNum<<endl;

}else if(mark==4){
    cout<<"请输入学生的准考证号"<<endl;
    string num;
    cin>>num;
    int x;
    for(x=0;x<64;x++)
    {
        if(seats[x].getNum()==num)
        {
            cout<<"该学生的座位为"<<x/8+1<<"行"<<x%8+1<<"列"<<endl;
            break;
        }
    }
    if(x==64){
    cout<<"没有此学生"<<endl;
}
}else if(mark==5){
    seatExam.displayList(seats);
}
}
}

