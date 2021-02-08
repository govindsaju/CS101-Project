#include <simplecpp>
#include <string>
#include <fstream>
#include <vector>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "bomb.h"
#include "booster.h"

using namespace simplecpp;

main_program {

  
  initCanvas("Lasso", WINDOW_X, WINDOW_Y);
  int stepCount = 0;
  float stepTime = STEP_TIME;
  float runTime = -1; // sec; -ve means infinite
  float currTime = 0;

  // Draw lasso at start position
  double release_speed = INIT_RELEASE_SPEED; // m/s
  double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
  double lasso_ax = LASSO_AX;
  double lasso_ay = LASSO_G;
  bool paused = true;
  bool rtheta = true;
  Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);

  //drawing x and y axes

  Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
  b1.setColor(COLOR("blue"));
  Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
  b2.setColor(COLOR("blue"));

  //initialising coin
  paused = true; rtheta = true;
  double coin_speed = COIN_SPEED;
  double coin_angle_deg = COIN_ANGLE_DEG;
  double coin_ax = COIN_AX;                                                  
  double coin_ay = COIN_G;
  Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);  

  //initialising bomb
  double bomb_speed = COIN_SPEED*1.5;
  double bomb_angle_deg = COIN_ANGLE_DEG*1.2;
  double bomb_ax = 0;
  double bomb_ay = COIN_G*0.9;
  Bomb bomb(bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);

  //initialising booster
  double booster_speed = COIN_SPEED*1.2;
  double booster_angle_deg = COIN_ANGLE_DEG;
  double booster_ax = 0;
  double booster_ay = COIN_G*1.2;
  Booster booster(booster_speed, booster_angle_deg, booster_ax, booster_ay, paused, rtheta);


  //obtaining and processing the data to be shown on screen
  
  string msg("Cmd: _");
  char lev[256];
  Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg);
  char coinScoreStr[256];
  sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
  sprintf(lev, "Lev: %d", coin.getlevel());
  Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+50, coinScoreStr);
  Text level(PLAY_X_START+50, PLAY_Y_HEIGHT+80, lev);

  char live[256];
  sprintf(live, "Liv: %d", coin.getlives());
  Text lives(PLAY_X_START+600, PLAY_Y_HEIGHT-450, live);

  //to retrieve the current high score from the file highscore.txt
  ifstream inp("highscore.txt");
  int best_score;
  inp >> best_score;
  char high_score[256];
  sprintf(high_score, "High: %d",best_score);
  Text highdisp(PLAY_X_START+600, PLAY_Y_HEIGHT-470, high_score);
  inp.close();



  //this is a variable used to get the loop to run once more after the lives become 0
  int flag = 0;

  // After every COIN_GAP sec, make the coin,bomb and booster jump
  double last_coin_jump_end = 0;
  double last_bomb_jump_end = 0;
  double last_booster_jump_end = 0;

  // When t is pressed, throw lasso
  // If lasso within range, make coin stick
  // When y is pressed, yank lasso
  // When l is pressed, loop lasso
  // When q is pressed, quit

  for(;;) {
    if((runTime > 0) && (currTime > runTime)) { break; }


    //this checks if there is any input from the user and if yes, takes the corresponding action

    XEvent e;
    bool pendingEv = checkEvent(e);
    if(pendingEv) {
      char c = charFromEvent(e);
      msg[msg.length()-1] = c;
      charPressed.setMessage(msg);
      switch(c) {
      case 't':
	lasso.unpause();
	break;
      case 'y':
	lasso.yank();
	break;
      case 'l':
	lasso.loopit();
	lasso.check_for_coin(&coin);
      lasso.check_for_bomb(&bomb);
      lasso.check_for_booster(&booster);
	wait(STEP_TIME*5);
	break;
      case '[':
	if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);	}
	break;
      case ']':
	if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
	break;
      case 'q':
	exit(0);
      default:
	break;
      }
    }

    lasso.nextStep(stepTime);

    coin.nextStep(stepTime);
    if(coin.isPaused()) {
      if((currTime-last_coin_jump_end) >= COIN_GAP) {
	coin.unpause();
      }
    }

    bomb.nextStep(stepTime);
    if (bomb.isPaused()){
      if((currTime-last_bomb_jump_end) >= COIN_GAP) {
      bomb.unpause();
      }
    }

    booster.nextStep(stepTime);
    if (booster.isPaused()){
      if((currTime-last_booster_jump_end) >= COIN_GAP)
      {
        booster.unpause();
      }

    }
    //updating the score and level on the display screen

    sprintf(coinScoreStr, "Coins: %d", lasso.getNumCoins());
    coinScore.setMessage(coinScoreStr);
    coin.setlevel(lasso.getNumCoins());
    sprintf(lev, "Lev: %d", coin.getlevel());
    level.setMessage(lev);

    sprintf(live, "Liv: %d", coin.getlives());
    lives.setMessage(live);

    //if any of the objects go below y axis, they are reset

    if(coin.getYPos() > PLAY_Y_HEIGHT) {
      coin.resetCoin();
      last_coin_jump_end = currTime;
    }

    if (bomb.getYPos()>PLAY_Y_HEIGHT){
      bomb.resetBomb();
      last_bomb_jump_end = currTime;
    }

    if (booster.getYPos()>PLAY_Y_HEIGHT)
    {
          booster.resetBooster();
          last_booster_jump_end = currTime;
    }

    //if level is 2 or more, bomb is activated
    if (coin.getlevel()<2) bomb.stopBomb();
    else if (coin.getlevel()>=2) bomb.startBomb();

    /*
    Here the lives are updated. The number of lives is a part of the coin class, while whether to increment or not is a part of the lasso class.
    Hence, data is taken from lasso and updated in coin.
    */
    if (lasso.getLifeincr())
    {
          coin.incrlives();
          lasso.resetLifeincr();
    }


    stepCount++;
    currTime += stepTime;
    wait(stepTime);

      if (coin.getlives()==0)
      {
      if (flag==1) break;
      coin.stopCoin();
      booster.stopBooster();
      bomb.stopBomb();
      flag=1;
      continue;
      }



  } // End for(;;)
  Text newhigh(380,250,"");

  //in the event of highscore being beaten, then we are updating the score and telling user that high score has been beaten
  
  if (lasso.getNumCoins()>best_score)
  {   ofstream outp("highscore.txt");
      outp<<lasso.getNumCoins();
      sprintf(high_score, "High: %d",lasso.getNumCoins());
      highdisp.setMessage(high_score);
      newhigh.setMessage("New High Score Achieved!!");
      outp.close();
  }



 getClick();
} // End main_program
