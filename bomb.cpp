#include "bomb.h"
#include "lasso.h"

void Bomb::initBomb() {
  if (stopstatus==false)
  {
    bomb_start_x = (PLAY_X_START+WINDOW_X)/2;
    bomb_start_y = PLAY_Y_HEIGHT;
    bomb_circle.reset(bomb_start_x, bomb_start_y, COIN_SIZE*1.2);
    bomb_circle.setColor(COLOR("red"));
    bomb_circle.setFill(true);
    addPart(&bomb_circle);
  }
} //end of initBomb

void Bomb::resetBomb() {
  if (stopstatus==false)
  {
    double bomb_speed = release_speed;
    double bomb_angle_deg = release_angle_deg;
    bomb_ax = 0;
    bomb_ay = COIN_G;
    bool paused = true, rtheta = true;
    reset_all(bomb_start_x, bomb_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
  }
} //end of resetBomb

void Bomb::stopBomb()
{
  stopstatus = true;
  release_speed = 0;
  bomb_circle.hide();
} //end of stopBomb

void Bomb::startBomb()
{
  stopstatus = false;
  release_speed = default_speed;
  bomb_circle.show();
}  //end of startBomb