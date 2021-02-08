#ifndef __BOOSTER_H__
#define __BOOSTER_H__

#include "MovingObject.h"

/*
Class booster is an object similar to coin. It is of two types, and randomly switches between the two each time it spawns.
Type 1: We get 2 coins instead of 1, and also get an additional life, but the speed of the lasso is reduced if we catch it. This is Blue in colour.
Type 2: We lose 2 coins on collecting tnis, but the speed of the lasso increases. This is purple in colour.
*/

class Booster : public MovingObject
{
  double booster_start_x;                                       //initial coordinates
  double booster_start_y;
  double release_speed;                                         //initial speed
  double default_speed;
  double release_angle_deg;
  double booster_ax;                                            //initial acceleration components
  double booster_ay;
  bool stopstatus;                                              //sets whether booster is spawning or not
  bool booster_status;                                          //sets whether booster is of type 1 or type 2, true implies type 1

  //moving portions
  Circle booster_circle;
  
  public:

/*
This is the constructor which is called on declaring the object. It sets the initial values on declaration.
*/

 Booster(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    booster_ax = argax;
    booster_ay = argay;
    stopstatus =  false;
    int t = rand()%2;                                         //generates a random number between 0 and 1
    if (t==1) booster_status = true;                          //if t==1, booster is set to type 1, else booster is of type 2
    else booster_status = false;
    initBooster();
  }
  //end of constructor

  void initBooster();                                         //used to set initial values
  void resetBooster();                                        //used to reset booster to initial position, and randomly allot the boosterstatus as well
  void stopBooster();                                         //used to stop booster from spawning
  void startBooster();                                        //used to start spawning of booster if it is currently stopped
  bool getStatus();                                           //used to return whether booster is of type 1 or type 2

  void startx();                                    //set starting location's x coordinate
  void starty();                                    //set starting location's y coordinate


};

#endif