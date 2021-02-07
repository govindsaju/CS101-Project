#include "booster.h"
#include "lasso.h"

void Booster::initBooster()
{
  if (stopstatus==false)
  {
    booster_start_x = (PLAY_X_START+WINDOW_X)/2;
    booster_start_y = PLAY_Y_HEIGHT;
    booster_circle.reset(booster_start_x, booster_start_y, COIN_SIZE);
    booster_circle.setColor(COLOR("blue"));
    booster_circle.setFill(true);
    addPart(&booster_circle);
  }

  
}

void Booster::resetBooster() {
  if (stopstatus==false)
  {
    double booster_speed = release_speed;
    double booster_angle_deg = release_angle_deg;
    if (booster_status==true) booster_status = false;
    else booster_status = true;
    booster_ax = 0;
    booster_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(booster_start_x, booster_start_y, booster_speed, booster_angle_deg, booster_ax, booster_ay, paused, rtheta);
  }
}

void Booster::stopBooster()
{
  stopstatus = true;
  release_speed = 0;
  booster_circle.hide();
}

void Booster::startBooster()
{
  stopstatus = false;
  release_speed = default_speed;
  booster_circle.show();
}