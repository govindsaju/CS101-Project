#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"


class Coin : public MovingObject {
  double coin_start_x;
  double coin_start_y;
  double release_speed;
  double default_speed;
  double release_angle_deg;
  double coin_ax;
  double coin_ay;
  int coin_level;
  bool stopstatus;


  // Moving parts
  Circle coin_circle;

 public:
 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta,int level=0) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    coin_ay = argay;
    coin_level = level;
    stopstatus = false;
    initCoin();
  }

  void initCoin();
  void resetCoin();
  void startx();
  void starty();
  void setlevel(int numcoin);
  int getlevel()
  {
    return coin_level;
  }

  void stopCoin();
  void startCoin();

}; // End class Coin

#endif