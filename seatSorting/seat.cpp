#include "seat.h"

seat::seat()
{
}
void seat::insertStu(string num,string name,student *seats)
{
    for(int i =0;i<64;i++)                  //�жϸ�ѧ���Ѿ����˿���
    {
        if(num==seats[i].getNum())
        {
            cout<<"��ѧ���Ѿ��ڿ�����Ӵ"<<endl;
            return ;
        }
    }
    int k=0;
    struct siteNum
    {
        int x;
        int y;
    }seatTmp[64];                       //��¼����û�˵���λ���кţ�������Щλ���������ȡһ��
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
    srand(time(NULL));          //�����������
    k=rand()%k;
    int seatX;
    int seatY;
    seatX=seatTmp[k].x;
    seatY=seatTmp[k].y;
    int x=(seatX-1)*8+seatY-1;
    (seats+x)->setNum(num);
    (seats+x)->setName(name);
    cout<<seatX<<"��"<<seatY<<"��"<<endl;
    ofstream fout("Examination seat.txt");//���Զ������ļ�
    for(int i=0;i<64;i++)
    {

        fout <<seats[i];
    }
        fout.flush();
        fout.close();

    return ;
}
void seat::deleteStu(string num,student *seats)             //����ĳ�˵Ŀ��ţ�ȡ��ĳ�˿�����λ
{
    for(int i =0;i<64;i++)
    {
        if(num==seats[i].getNum())
        {
            seats[i].setNum("0");
            cout<<"ѧ��"<<seats[i].getName()<<"("<<num<<")"<<"��λ�ѳɹ���ȡ��Ӵ"<<endl;
            return ;
        }

    }
    cout<<"�ÿ���"<<"("<<num<<")"<<"���ڿ���"<<endl;
    ofstream fout("Examination seat.txt");//���Զ������ļ�
    for(int i=0;i<64;i++)
    {

        fout <<seats[i];
    }
        fout.flush();
        fout.close();

    return ;

}
void seat::displayStu(int x,int y,student *seats)            //������λ���кź��кţ�Ȼ����ʾ����λѧ������Ϣ
{
    if(x<1||x>8||y<1||y>8)
    {
        cout<<"��������û�����λ��"<<endl;
        return ;

    }
    cout<<"����"<<(seats+(x-1)*8+y-1)->getName()<<"ѧ��:"<<(seats+(x-1)*8+y-1)->getNum()<<endl;
    return ;
}
void seat::displayList(student *seats)              //ʾ�������α���ÿ����λ��Ӧ����������ʾ�ÿ�����׼��֤�ţ������������α�����ļ���
{
    int x,y;
    cout<<"��������λ��Ϣ"<<endl;
    for ( x=0; x<8; x++)
    {
        for (y=0; y<8; y++)
        {
            if (seats[x*8+y].getNum() != "0") //��Ϊ0������
            {
                //�����������룬�п�10
                cout.flags(ios::left);
                cout<<setw(10)<<(seats[x*8+y].getNum());//�������׼��֤��
            }else{
            cout.flags(ios::left);
            cout<<setw(10)<<"_______";//_____Ϊ����
            }
        }
    cout<<endl;
    }
    cout<<endl;
}
