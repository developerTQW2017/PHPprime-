#include <QCoreApplication>
#include <iostream>
#include<tdatetime.h>
#include<tvechicle.h>
#include <car_type.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct link
{
    TVehicle  Car;
    struct link*next;
};
struct link*AppendNode(struct link*head)           //函数功能：新建一个节点并添加到链表末段，返回添加节点后链表的头指针
{
    struct link*p1 = NULL, *p2 = head;
   TVehicle Car;
    p1 = (struct link*)malloc(sizeof(struct link));        //让p1指向新建节点
    if (p1 == NULL)                       //若为新建节点申请内存失败则退出程序
    {
        cout << "内存不足！" << endl;
        exit(0);
    }
    if (head == NULL)                  //若原链表为空表
    {
        head = p1;                     //将新建节点置为头节点
    }
    else                             //若原链表为非空，则将新建节点添加到表尾
    {
        while (p2->next != NULL)             //若未到表尾，则移动p2直到p2指向表尾
        {
            p2 = p2->next;                     //让p2指向下一个节点
        }
        p2->next = p1;                        //让末节点指针指向新建节点

    }
    cout << "请输入车牌号：";
    cin >>Car.che_pai_hao;
    p1->Car.che_pai_hao = Car.che_pai_hao;                   //将新建节点的数据域赋值为输入的节点的数据值
    p1->next = NULL;                                         //将新建节点置为表尾
    return head;                               //返回添加节点后链表的头指针
}
void DisplyNode(struct link*head)            //显示链表中所有节点的节点号和该节点中的数据项内容
{
    struct link*p1 = head;
    string thenumber;
    if (thenumber == p1->Car.che_pai_hao)
    {
        cout << "车牌号：" << p1->Car.che_pai_hao;
        cout << "停车时长：" << p1->Car.shichang();
        cout << "费用：" << p1->Car.EXPENSE();
    }
    p1 = p1->next;
}


void DeleteMemory(struct link*head)                 //释放lead指向的链表中所有节点所占的内存
{
    struct link*p1 = head, *p2 = NULL;
    while (p1 != NULL);
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }

}

void Checkinfro()
{
    struct link*head = NULL;                   //链表头指针
    head = AppendNode(head);                          //向head为头指针的链表末尾添加节点
    DisplyNode(head);                      //显示信息
    DeleteMemory(head);
}

int main()
{ void Checkinfro();
    int op1, op2,op3;
   TVehicle Car;
    A:cout << "车辆类型：（1）卡车 （2）轿车 "<<endl;
    cin >> op1;
    switch (op1)
    {
    case 1:
        cout << "请选择：（1）车辆进场 （2）车辆出场 (3)查询车辆信息"<<endl;
        cin >> op2;
        switch (op2)
        {
        case 1:
            cout << "请输入车牌号：";
            cin >> Car.che_pai_hao;
            Car.getstop_time();
            cout << endl;
            break;
        case 2:
            Car.getput_out_time();
           Car. shichang();
            Car.EXPENSE();
            cout << endl;
            break;
     case 3:
            Checkinfro();
        }
        goto A;
case 2:
        cout << "请选择：（1）车辆进场 （2）车辆出场 （3）查询车辆信息 ";
        cin >> op3;
        switch (op3)
        {
        case 1:
            cout << "请输入车牌号：";
            cin >> Car.che_pai_hao;
            Car.getstop_time();
            cout << endl;
            break;
        case 2:
            Car.getput_out_time();
           Car. shichang();
            Car.EXPENSE();
            cout << endl;
            break;
     case 3:
            Checkinfro();
            break;

        }
        goto A;

    }
return 0;
}
