#include "coin.h"
#include "lasso.h"


void Coin::initCoin() {
  if (stopstatus==false)
  {
    coin_start_x = (PLAY_X_START+WINDOW_X)/2;
    coin_start_y = PLAY_Y_HEIGHT;
    
    coin_circle.reset(coin_start_x, coin_start_y, COIN_SIZE);
    coin_circle.setColor(COLOR("gold"));
    coin_circle.setFill(true);
    addPart(&coin_circle);
  }
}
//end of initCoin


void Coin::resetCoin() {
  if (stopstatus==false)
  {
    double coin_speed = COIN_SPEED;
    double coin_angle_deg = COIN_ANGLE_DEG;
    coin_ax = COIN_AX;
    coin_ay = COIN_G;
    bool paused = true, rtheta = true;

    if (coin_circle.getY()>PLAY_Y_HEIGHT) decrlives();                //if the coin goes below y axis, then it was not caught, hence a life is reduced

    startx();
    starty();
    reset_all(coin_start_x, coin_start_y, coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
  }
}
//end of resetCoin


void Coin::startx()
{
  if (coin_level==0) coin_start_x=(PLAY_X_START+WINDOW_X)/2;          //for level 0, starting location is from a fixed point
  else coin_start_x= PLAY_X_START+rand()%(WINDOW_X-PLAY_X_START);     //for level 1 and above, coin is launched from a random point
}
//end of startx

void Coin::starty()
{ 
  if (coin_level==0) coin_start_y = (PLAY_Y_HEIGHT);                  //level 0- fixed starting point
  else coin_start_y = ((PLAY_Y_HEIGHT) - rand()%(PLAY_Y_HEIGHT/5));   //level 1- random starting point
}
//end of starty



void Coin::setlevel(int numcoin)
{
  if (numcoin>7) coin_level=3;                                        //sets the level on basis of current number of coins
  if (numcoin>2 and numcoin<=5) coin_level=1;
  else if (numcoin>5 and numcoin<=7) coin_level=2;
  else if (numcoin>=0 and numcoin<=2) coin_level=0;
}
//end of setlevel



void Coin::stopCoin()
{
  stopstatus = true;
  release_speed = 0;
  coin_circle.hide();
}
//end of stopCoin

void Coin::startCoin()
{
  stopstatus = false;
  release_speed = default_speed;
  coin_circle.show();
}
//end of startCoin



void Coin::decrlives()
{
  if (lives>0) lives--;
}
//end of decrlives

void Coin::incrlives()
{
  lives++;
}
//end of incrlives

int Coin::getlives()
{
  return lives;
}
//end of getlives


int Coin::getlevel()
{
  return coin_level;
}
//end of getlevel

