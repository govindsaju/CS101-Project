#include "coin.h"
#include "lasso.h"



void Coin::initCoin() {
  if (stopstatus==false)
  {
    coin_start_x = (PLAY_X_START+WINDOW_X)/2;
    coin_start_y = PLAY_Y_HEIGHT;
    //coin_start_x = startx();
    //coin_start_y = starty();
    
    coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
    coin_circle.setColor(COLOR("gold"));
    coin_circle.setFill(true);
    addPart(&coin_circle);
  }
}

void Coin::resetCoin() {
  if (stopstatus==false)
  {
    double coin_speed = COIN_SPEED;
    double coin_angle_deg = COIN_ANGLE_DEG;
    coin_ax = COIN_AX;
    coin_ay = COIN_G;
    bool paused = true, rtheta = true;
    startx();
    starty();
    reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  }
}

void Coin::startx()
{
  if (coin_level==0) coin_start_x=(PLAY_X_START+WINDOW_X)/2;
  else coin_start_x= PLAY_X_START+rand()%(WINDOW_X-PLAY_X_START);
}

void Coin::starty()
{ 
  if (coin_level==0) coin_start_y = (PLAY_Y_HEIGHT);
  else coin_start_y = ((PLAY_Y_HEIGHT) - rand()%(PLAY_Y_HEIGHT/5));
}

void Coin::setlevel(int numcoin)
{
  if (numcoin>7) coin_level=3;
  if (numcoin>2 and numcoin<=5) coin_level=1;
  else if (numcoin>5 and numcoin<=7) coin_level=2;
  else if (numcoin>=0 and numcoin<=2) coin_level=0;
}

void Coin::stopCoin()
{
  stopstatus = true;
  release_speed = 0;
  coin_circle.hide();
}

void Coin::startCoin()
{
  stopstatus = false;
  release_speed = default_speed;
  coin_circle.show();
}

