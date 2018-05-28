#include "tvechicle.h"
#include"tdatetime.h"
#include "time.h"
TVehicle::TVehicle()//默认构造函数
{
}
void TVehicle:: getstop_time()//获取停车时间
{  TDateTime JRtime;
    JRtime.printf();
}
void TVehicle::getput_out_time()//获取提车时间
{
      TDateTime CQtime;
    CQtime.printf();
}
int TVehicle:: shichang()//计算时长
 {
       TDateTime  CQtime1;
      TDateTime JRtime1;
   return H_shichang=(CQtime1-JRtime1)/60;
 }

int TVehicle:: EXPENSE()//计算费用
{
    if(H_shichang*60<30)
        return 0;
    else if(H_shichang*60>60&&((H_shichang*60-60)>15))
    return ((H_shichang*60/60)+1)*6;
    else
        return 6;
}
