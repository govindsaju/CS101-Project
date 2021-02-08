This is a project done by Govind Saju, student of IIT Bombay (roll number 200070020) for the course CS-101 for the academic year 2020-2021.
It is an implementation oriented project done on simplecpp graphics. A starter code was given for the game, and we had to build on it.

This project was done on Ubuntu 18, and compilation was done using the following command on the Ubuntu terminal:
s++ -o lasso lasso.cpp coin.cpp main.cpp MovingObject.cpp bomb.cpp booster.cpp

This results in an executable lasso, which can be run by
./lasso
assuming that we are in the same working directory throughout.

The help document for instructions on playing the game can be found in the document instructions.pdf


The major enhancements in this project over the starter code are:
  1) The trajectory of the coin is changed to a parabolic one over the linear one in the starter code.
  2) Minor bug fix: in starter code, after we collected a single coin, yanking the lasso (control y) constantly increased the number of coins, irrespective of whether we caught the coin or not. This has been fixed.
  3) A concept of game levels has been introduced. There are 4 levels - lv 0, lv 1, lv 2, lv 3. These are based on our current score, that is the current number of coins. The game increases in difficulty level by level.
  4) Bombs, which are coins that should not be collected have been added. They are red in colour, and catching them results in a decrease in the score.
  5) Introduction of Booster: The starter code had controls to increase or decrease the speed of the lasso. In this project, that has been done away with. Instead, boosters of two types are added, which is the only way to control speed of lasso. More details regarding this have been added to the help document.
  6) Spawning of coins made random: in starter code, spawning of coins was from  fixed point. In this project, the coins spawn from random points after a certain level.
  7) The concept of lives added: in the starter code, the game could go on indefinitely. In the project, the player starts with a certain number of lives. On missing to catch a coin, lives are reduced. Lives can be gained by certain boosters.
  8) The high score of the player is also stored in a file now. If the player scores more than the current value, then the high score is also updated in the file.
  
