#ifndef __BOMB_H__
#define __BOMB_H__

#include "MovingObject.h"

class Bomb : public MovingObject
{
  double bomb_start_x;
  double bomb_start_y;
  double release_speed;
  double default_speed;
  double release_angle_deg;
  double bomb_ax;
  double bomb_ay;
  bool stopstatus;
  

    // Moving parts
  Circle bomb_circle;
 public:
 Bomb(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    bomb_ax = argax;
    bomb_ay = argay;
    stopstatus =  false;
    initBomb();
  }

  void initBomb();
  void resetBomb();
  void stopBomb();
  void startBomb();

}; // End class bomb




#endif