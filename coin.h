#ifndef __COIN_H__
#define __COIN_H__

#include "MovingObject.h"
#define MAX_LIVES 1

class Coin : public MovingObject {
  double coin_start_x;                              //starting coordinates
  double coin_start_y;
  double release_speed;                             //starting speed
  double default_speed;
  double release_angle_deg;
  double coin_ax;                                   //starting acceleration
  double coin_ay;
                                
  bool stopstatus;                                  //to store whether the coin is currently stopped or not, true implies that it is stopped.
  
  int lives;                                        //to store the number of lives left, on reaching 0 the game ends. We lose a life for each coin missed.
  int coin_level;                                   //to store the current level of the game, difficulty increases at higher levels

  // Moving parts
  Circle coin_circle;

 public:
/*
This is the constructor called when object is declared. It sets all the default values for the different parameters.
*/

 Coin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta,int level=0) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    coin_ax = argax;
    lives = MAX_LIVES;
    coin_ay = argay;
    coin_level = level;
    stopstatus = false;
    initCoin();
  }
  //end of constructor

  void initCoin();                                  //used to set default values along with constructor
  void resetCoin();                                 //used to reset coin, and spawn it again
  void startx();                                    //set starting location's x coordinate
  void starty();                                    //set starting location's y coordinate
  void setlevel(int numcoin);                       //to set the level of the game based on the number of coins collected

  void decrlives();                                 //used to reduce the number of lives by 1
  void incrlives();                                 //used to increase the number of lives by 1
  int getlives();                                   //returns the number of lives left
  int getlevel();                                   //returns the current level of the game


  void stopCoin();                                  //used to stop coins from spawning
  void startCoin();                                 //used to restart the spawning of the coins

}; // End class Coin

#endif
