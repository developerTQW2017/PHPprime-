#include "seat.h"

seat::seat()
{
}
void seat::insertStu(string num,string name,student *seats)
{
    for(int i =0;i<64;i++)                  //判断该学生已经到了考场
    {
        if(num==seats[i].getNum())
        {
            cout<<"该学生已经在考场了哟"<<endl;
            return ;
        }
    }
    int k=0;
    struct siteNum
    {
        int x;
        int y;
    }seatTmp[64];                       //记录所有没人的座位行列号，并在这些位置中随机抽取一个
    int j;
    int i;
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
        {
            if(seats[i*8+j].getNum()=="0")
            {
                seatTmp[k]={i+1,j+1};
                k++;

            }

        }
    }
    srand(time(NULL));          //设置随机种子
    k=rand()%k;
    int seatX;
    int seatY;
    seatX=seatTmp[k].x;
    seatY=seatTmp[k].y;
    int x=(seatX-1)*8+seatY-1;
    (seats+x)->setNum(num);
    (seats+x)->setName(name);
    cout<<seatX<<"行"<<seatY<<"列"<<endl;
    ofstream fout("Examination seat.txt");//能自动创建文件
    for(int i=0;i<64;i++)
    {

        fout <<seats[i];
    }
        fout.flush();
        fout.close();

    return ;
}
void seat::deleteStu(string num,student *seats)             //输入某人的考号，取消某人考场座位
{
    for(int i =0;i<64;i++)
    {
        if(num==seats[i].getNum())
        {
            seats[i].setNum("0");
            cout<<"学生"<<seats[i].getName()<<"("<<num<<")"<<"座位已成功被取消哟"<<endl;
            return ;
        }

    }
    cout<<"该考生"<<"("<<num<<")"<<"不在考场"<<endl;
    ofstream fout("Examination seat.txt");//能自动创建文件
    for(int i=0;i<64;i++)
    {

        fout <<seats[i];
    }
        fout.flush();
        fout.close();

    return ;

}
void seat::displayStu(int x,int y,student *seats)            //输入座位的行号和列号，然后显示该座位学生的信息
{
    if(x<1||x>8||y<1||y>8)
    {
        cout<<"。。。。没有这个位置"<<endl;
        return ;

    }
    cout<<"考生"<<(seats+(x-1)*8+y-1)->getName()<<"学号:"<<(seats+(x-1)*8+y-1)->getNum()<<endl;
    return ;
}
void seat::displayList(student *seats)              //示考场座次表，在每个座位对应的行列上显示该考生的准考证号，并将考场座次表存入文件。
{
    int x,y;
    cout<<"本考场座位信息"<<endl;
    for ( x=0; x<8; x++)
    {
        for (y=0; y<8; y++)
        {
            if (seats[x*8+y].getNum() != "0") //不为0则有人
            {
                //输出的行左对齐，列宽10
                cout.flags(ios::left);
                cout<<setw(10)<<(seats[x*8+y].getNum());//有人输出准考证号
            }else{
            cout.flags(ios::left);
            cout<<setw(10)<<"_______";//_____为无人
            }
        }
    cout<<endl;
    }
    cout<<endl;
}
