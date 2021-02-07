#ifndef __BOOSTER_H__
#define __BOOSTER_H__

#include "MovingObject.h"

class Booster : public MovingObject
{
  double booster_start_x;
  double booster_start_y;
  double release_speed;
  double default_speed;
  double release_angle_deg;
  double booster_ax;
  double booster_ay;
  bool stopstatus;
  bool booster_status;

  //moving portions
  Circle booster_circle;
  
  public:

 Booster(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    booster_ax = argax;
    booster_ay = argay;
    stopstatus =  false;
    booster_status = true;
    initBooster();
  }

  void initBooster();
  void resetBooster();
  void stopBooster();
  void startBooster();
  bool getStatus()
  {
    return booster_status;
  }


};

#endif