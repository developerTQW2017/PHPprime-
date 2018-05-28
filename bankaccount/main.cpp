#include <iostream>
#include <bankaccount.h>
#include <string>
#include <cdaccount.h>
#include <moneymarketaccount.h>
#include <fstream>
using namespace std;
int pan(string text)
{
    fstream file;
        int ch;
        file.open(text,ios::in);
        ch=file.get(); //试图去读一个字符
        if(ch) //或 if ( ch==EOF )  //一个字符都未读到，表示文件为空
        {
            return 1;
        }
        file.close();
        return 0;
}
//int xierujia(string a,double b,BankAccount *jia)
//{
//    ifstream fin;
//    fin.open("jia.dat",ios::in);
//    if(!fin)
//    {
//        cout<<"Cannot open input file.\n";
//        return 1;
//    }
//    fin>>a;
//    fin>>b;
//    jia=new BankAccount(a,b);
//    fin.close();
//}
//int shuruyi(string a,double b,double c,bool d,CDAccount *yi)
//{
//    ifstream fin;
//    fin.open("yi.dat",ios::in);
//    if(!fin)
//    {
//        cout<<"Cannot open input file.\n";
//        return 1;
//    }
//    fin>>a>>b>>c>>d;
//    yi=new CDAccount(a,b,c,d);
//    fin.close();

//}
//int shurubing(string a,double b,MoneyMarketAccount *bing)
//{
//    ifstream fin;
//    fin.open("jia.dat",ios::in);
//    if(!fin)
//    {
//        cout<<"Cannot open input file.\n";
//        return 1;
//    }
//    fin>>a>>b;
//    bing=new MoneyMarketAccount(a,b);
//    fin.close();
//}

int main()
{
    while(1){
    string a;
    double b;
    double c;
    bool d;
    int times;
    int intpan=pan("jia.dat");
        if(intpan==0)
        {
            ofstream fin;
            fin.open("jia.dat",ios::out);
            fin<<"jia";
            fin<<500;
            fin.close();
        }
    ifstream fin;
    fin.open("jia.dat",ios::in);
    if(!fin)
    {
        cout<<"Cannot open input file.\n";
        return 1;
    }
    fin>>a;
    fin>>b;
    BankAccount *jia=new BankAccount(a,b);
    fin.close();


    int intpan1=pan("yi.dat");
        if(intpan1==0)
        {
            ofstream fin1;
            fin1.open("yi.dat",ios::out);
            fin1<<"yi";
            fin1<<500;
            fin1.close();
        }
    ifstream fin1;
    fin1.open("yi.dat",ios::in);
    if(!fin1)
    {
        cout<<"Cannot open input file.\n";
        return 1;
    }
    fin1>>a;
    fin1>>b;
    CDAccount *yi=new CDAccount(a,b,c,d);
    fin1.close();

    int intpan2=pan("bing.dat");
        if(intpan2==0)
        {
            ofstream fin2;
            fin2.open("bing.dat",ios::out);
            fin2<<"bing";
            fin2<<500;
            fin2<<0;
            fin2.close();
        }
    ifstream fin2;
    fin2.open("bing.dat",ios::in);
    if(!fin2)
    {
        cout<<"Cannot open input file.\n";
        return 1;
    }
    fin2>>a;
    fin2>>b;
    fin2>>times;
    MoneyMarketAccount *bing=new MoneyMarketAccount(a,b,times);
    fin.close();
//    MoneyMarketAccount *bing=new MoneyMarketAccount("bing",500);
//    BankAccount *jia=new BankAccount("jia",500);
//    int intpan;
//    intpan=pan("jia.dat");
//    if(intpan==0)
//    {
//        xierujia(a,b,jia);
//    }
//    intpan=pan("yi.dat");
//    CDAccount *yi=new CDAccount("yi",500,0.035,1);
//    if(intpan==0)
//    {
//        shuruyi(a,b,c,d,yi);
//    }
//    intpan=pan("bing.dat");
//    MoneyMarketAccount *bing=new MoneyMarketAccount("bing",500);
//    if(intpan==0)
//    {
//        shurubing(a,b,bing);
//    }


    int op;
    cout<<"1.存款输入1"<<endl;
    cout<<"2.取款输入2"<<endl;
    cout<<"3.转账输入3"<<endl;
    cout<<"4.查看余额"<<endl;
    cin>>op;
    string acc;string yAcc,tAcc;
    double money;
    if(op==1)
    {
        cout<<"请选择存入账户1.jia 2.yi 3.bing"<<endl;
        cin>>acc;
        cout<<"请输入金额";
        cin>>money;

        if(acc=="jia")
        {
            jia->deposit(money);

        }else if(acc=="yi"){
            yi->deposit(money);

        }else if(acc=="bing"){
            bing->deposit(money);

        }else{
            cout<<"请输入指定内账户"<<endl;


        }
        ofstream fout8("jia.dat",ios::out);
        fout8<<jia->getName()<<endl;
        fout8<<jia->getBalance()<<endl;
        fout8.close();
        ofstream fout9("yi.dat",ios::out);
        fout9<<yi->getName()<<endl;
        fout9<<yi->getBalance()<<endl;
//        fout9<<yi->getInterest()<<endl;
//        fout9<<yi->getTiqian()<<endl;
        fout9.close();
        ofstream fout0("bing.dat",ios::out);
        fout0<<bing->getName()<<endl;
        fout0<<bing->getBalance()<<endl;
        fout0<<bing->getTimes()<<endl;
        fout0.close();

    }else if(op==2){
                cout<<"请选择取款账户1.jia 2.yi 3.bing"<<endl;
                cin>>acc;
                cout<<"请输入金额";
                cin>>money;
                if(acc=="jia")
                {
                    jia->withdraw(money);

                }else if(acc=="yi"){
                    yi->withdraw(money);


                }else if(acc=="bing"){
                    bing->withdraw(money);

                }else{
                    cout<<"请输入指定内账户"<<endl;

                }
                ofstream fout11("jia.dat",ios::out);
                fout11<<jia->getName()<<endl;
                fout11<<jia->getBalance()<<endl;
                fout11.close();
                ofstream fout12("yi.dat",ios::out);
                fout12<<yi->getName()<<endl;
                fout12<<yi->getBalance()<<endl;
                fout12<<yi->getInterest()<<endl;
                fout12<<yi->getTiqian()<<endl;
                fout12.close();
                ofstream fout13("bing.dat",ios::out);
                fout13<<bing->getName()<<endl;
                fout13<<bing->getBalance()<<endl;
                fout13<<bing->getTimes()<<endl;
                fout13.close();


        }else if(op==3){

        cout<<"请选择转入账户1.jia 2.yi 3.bing"<<endl;
        cin>>yAcc;
        cout<<"请输入金额";
        cin>>money;
        cout<<"请选择转出账户1.jia 2.yi 3.bing"<<endl;
        cin>>tAcc;
        if(yAcc=="jia")
        {
            jia->deposit(money);

        }else if(yAcc=="yi"){
            yi->deposit(money);

        }else if(yAcc=="bing"){
            bing->deposit(money);
        }else{
            cout<<"请输入指定内账户"<<endl;

        }
        if(tAcc=="jia")
        {
            jia->withdraw(money);


        }else if(tAcc=="yi"){
            yi->withdraw(money);


        }else if(tAcc=="bing"){
            bing->withdraw(money);

        }else{
            cout<<"请输入指定内账户"<<endl;
        }
        ofstream fout("jia.dat",ios::out);
        fout<<jia->getName()<<endl;
        fout<<jia->getBalance()<<endl;
        fout.close();
        ofstream fout1("yi.dat",ios::out);
        fout1<<yi->getName()<<endl;
        fout1<<yi->getBalance()<<endl;
//        fout1<<yi->getInterest()<<endl;
//        fout1<<yi->getTiqian()<<endl;
        fout1.close();
        ofstream fout3("bing.dat",ios::out);
        fout3<<bing->getName()<<endl;
        fout3<<bing->getBalance()<<endl;
        fout3<<bing->getTimes()<<endl;
        fout3.close();



    }

}
}
