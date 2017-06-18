#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <student.h>
#include <seat.h>
#include <fstream>
using namespace std;
istream& operator>>(istream&is, student&st)//ifstream��isream�����࣬Ҳ����Ϊ�����Ĳ���
{
    is >> st.stuName;
    is>>st.stuNum;
    return is;
}

ostream& operator<<(ostream&os, const student&st)//ofstream��osream�����࣬Ҳ����Ϊ�����Ĳ���
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
cout<<setw(40)<<"1���趨������λ"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"2��ȡ��������λ"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"3����ʾĳ��λ������Ϣ"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"4������ѧ����λ"<<endl;
cout<<setw(10)<<" ";
cout<<setw(40)<<"5���鿴������λ��"<<endl;
int mark;
cin>>mark;

if(mark==1)
{
    string num1;
    string name1;

    cout<<"������׼��֤��"<<endl;
    cin>>num1;
    cout<<"����������"<<endl;
    cin>>name1;
    seatExam.insertStu(num1,name1,seats);
}else if(mark==2){
    cout<<"��������Ҫȡ����ѧ����׼��֤��"<<endl;
    string num;
    cin>>num;
    seatExam.deleteStu(num,seats);

}else if(mark==3){
    int hang,lie;
    cout<<"����������Ҫ�鿴��ѧ���к�"<<endl;
    cin>>hang;
    cout<<"����������Ҫ�鿴��ѧ���к�"<<endl;
    cin>>lie;
    int si=(8*(hang-1)+lie-1);
    cout<<si;
    cout<<"����:"<<seats[si].stuName<<"ѧ��:"<<seats[si].stuNum<<endl;

}else if(mark==4){
    cout<<"������ѧ����׼��֤��"<<endl;
    string num;
    cin>>num;
    int x;
    for(x=0;x<64;x++)
    {
        if(seats[x].getNum()==num)
        {
            cout<<"��ѧ������λΪ"<<x/8+1<<"��"<<x%8+1<<"��"<<endl;
            break;
        }
    }
    if(x==64){
    cout<<"û�д�ѧ��"<<endl;
}
}else if(mark==5){
    seatExam.displayList(seats);
}
}
}

