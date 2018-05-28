#include "car_type.h"
#include"tdatetime.h"
#include"tvechicle.h"
car_type::car_type()
    :TVehicle()
{
string tp;
type=tp;
}
int car_type::EXPENSE()
{
    if(H_shichang*60<30)
        return 0;
    else if(H_shichang*60>60&&((H_shichang*60-60)>15))
    return ((H_shichang*60/60)+1)*20;
    else
        return 20;
}

car_type::~car_type()
{
cout<<"All!"<<endl;
}

