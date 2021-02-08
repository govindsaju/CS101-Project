#ifndef __BOMB_H__
#define __BOMB_H__

#include "MovingObject.h"

/*
The class bomb is similar to coin. It is red in colour, and spawns periodically.
Bombs are to be avoided, catching it leads to a reduction in points.
*/
class Bomb : public MovingObject
{
  double bomb_start_x;                //starting coordinates
  double bomb_start_y;
  double release_speed;               //starting speed
  double default_speed;               
  double release_angle_deg;           //starting release angle
  double bomb_ax;                     //value of acceleration ax - x axis, ay - y axis
  double bomb_ay;
  bool stopstatus;                    //used to store whether bombs are being spawned currently or not, true implies bombs are not spawned.
  

    // Moving parts
  Circle bomb_circle;
 public:

 /*
This is the constructor, used to set all default values for the bomb class/
 */
 Bomb(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    bomb_ax = argax;
    bomb_ay = argay;
    stopstatus =  false;
    initBomb();
  }

  

  void initBomb();                    //called by constructor to initiate different parameters of bomb
  void resetBomb();                   //used to reset bomb to initial position and respawn
  void stopBomb();                    //to completely stop bombs from spawning
  void startBomb();                   //used to restart spawning of bombs if they are currently stopped

}; // End class bomb




#endif