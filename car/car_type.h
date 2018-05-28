#ifndef CAR_TYPE_H
#define CAR_TYPE_H
#include "car_type.h"
#include"tdatetime.h"
#include"tvechicle.h"
class car_type:public TVehicle
{
private:
    string type;
public:
  car_type();
 virtual int EXPENSE();
    ~car_type();
};

#endif // CAR_TYPE_H
