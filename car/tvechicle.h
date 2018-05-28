#ifndef TVECHICLE_H
#define TVECHICLE_H
#include <string>
#include <tdatetime.h>
#include<ctime>
using namespace  std;

class TVehicle
{
public:
    TVehicle();//默认构造函数
  void getstop_time();//获取停车时间
   void getput_out_time();//获取提车时间
     virtual int EXPENSE();//计算费用
    int shichang();//计算时长
  string che_pai_hao;
    float H_shichang;
    TVehicle *next;
    TVehicle *pre;
};

#endif // TVECHICLE_H
