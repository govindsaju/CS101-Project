#ifndef __LASSO_H__
#define __LASSO_H__

#include "MovingObject.h"
#include "coin.h"
#include "bomb.h"
#include "booster.h"

//#define WINDOW_X 1200
//#define WINDOW_Y 960
#define WINDOW_X 800
#define WINDOW_Y 600

#define STEP_TIME 0.05

#define PLAY_X_START 100
#define PLAY_Y_START 0
#define PLAY_X_WIDTH (WINDOW_X-PLAY_X_START)
#define PLAY_Y_HEIGHT (WINDOW_Y-100)

#define LASSO_X_OFFSET 100
#define LASSO_Y_HEIGHT 100
#define LASSO_BAND_LENGTH LASSO_X_OFFSET
#define LASSO_THICKNESS 5

#define COIN_GAP 1

#define RELEASE_ANGLE_STEP_DEG 5
#define MIN_RELEASE_ANGLE_DEG 0
#define MAX_RELEASE_ANGLE_DEG (360-RELEASE_ANGLE_STEP_DEG)
#define INIT_RELEASE_ANGLE_DEG 45

#define RELEASE_SPEED_STEP 20
#define MIN_RELEASE_SPEED 0
#define MAX_RELEASE_SPEED 200
#define INIT_RELEASE_SPEED 100

#define COIN_SPEED 120
#define COIN_ANGLE_DEG 115          

#define LASSO_G 30
#define COIN_G 30
#define LASSO_AX 10
#define COIN_AX -3

#define LASSO_SIZE 10
#define LASSO_RADIUS 50
#define COIN_SIZE 7

class Lasso : public MovingObject {
  double lasso_start_x;
  double lasso_start_y;
  double release_speed;
  double default_speed;
  double release_angle_deg;
  double lasso_ax;
  double lasso_ay;

  bool lifeincr;

  // Moving parts
  Circle lasso_circle;
  Circle lasso_loop;

  // Non-moving parts
  Line lasso_line;
  Line lasso_band;

  // State info
  bool lasso_looped;
  Coin *the_coin;
  Bomb *the_bomb;
  Booster *the_booster;
  int num_coins;

  void initLasso();
 public:
 Lasso(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    default_speed = speed;
    release_angle_deg = angle_deg;
    lasso_ax = argax;
    lasso_ay = argay;
    lifeincr = false;
    initLasso();
  }


  void draw_lasso_band();                                   //to draw lasso
  void yank();                                              //to yank lasso
  void loopit();                                            //to loop the lasso
  void addAngle(double angle_deg);                          //to increase angle of launch to lasso
  void addSpeed(double speed);                              //to decrease angle of launch of lasso
  void resetLassospeed();                                   //to reset lasso speed back to normal



  void nextStep(double t);                                  

  
  //to check whether coins, bombs, or boosters have been caught

  void check_for_coin(Coin *coin);
  void check_for_bomb(Bomb *bomb);
  void check_for_booster(Booster *booster);


  int getNumCoins() { return num_coins; }                   //returns number of coins
  void decr_coins();                                        //decreases coins by 1 after if number of coins is more than 0
  void resetLifeincr();                                     //to reset lifeincr status to false after incrementing lives
  bool getLifeincr();                                       //to check whether lives are to be incremented or not based on whether booster is collected


}; // End class Lasso

#endif
