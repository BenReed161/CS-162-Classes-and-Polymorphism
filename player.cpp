/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: player.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the player class and handles all the player functionalilty.
*********************************************************************/ 
#include "player.h"
/*********************************************************************  
** Function: Player
** Description: player constructor, arrows are set equal to 4 because
the way I took arrows away made it so I had to add one arrow more, but
the play can still only shoot 3 times.
*********************************************************************/ 
Player::Player(){
    arrows = 4;
}
/*********************************************************************  
** Function: gold
** Description: function that sets hasGold to true or false
** Parameters: val 
*********************************************************************/ 
void Player::gold(bool val){
    hasGold = val;
}
/*********************************************************************  
** Function: returnGold
** Description: function that returns hasGold
** Post-Conditions: return bool
*********************************************************************/ 
bool Player::returnGold(){
    return hasGold;
}
/*********************************************************************  
** Function: getPlayerX
** Description: Function that returns the playerX
** Post-Conditions: reutrn int
*********************************************************************/ 
int Player::getPlayerX(){
    return playerX;
}
/*********************************************************************  
** Function: getPlayerY
** Description: Function that returns the playerY
** Post-Conditions: return int
*********************************************************************/ 
int Player::getPlayerY(){
    return playerY;
}
/*********************************************************************  
** Function: getArrows
** Description: Function that returns the arrows
** Post-Conditions: return int
*********************************************************************/ 
int Player::getArrows(){
    return arrows;
}
/*********************************************************************  
** Function: getPlayerOriginX
** Description: Function that returns the getPlayerOriginX
** Post-Conditions: return int
*********************************************************************/ 
int Player::getPlayerOriginX(){
    return originPlayerX;
}
/*********************************************************************  
** Function: getPlayerOriginY
** Description: Function that returns the getPlayerOriginY
** Post-Conditions: return int
*********************************************************************/ 
int Player::getPlayerOriginY(){
    return originPlayerY;
}
/*********************************************************************  
** Function: removeArrow
** Description: Function that decrements the arrows
** Post-Conditions: arrow --
*********************************************************************/ 
void Player::removeArrow(){
    arrows--;
}
/*********************************************************************  
** Function: setArrows
** Description: Function that sets the arrows to a specific value.
** Parameters: a
*********************************************************************/ 
void Player::setArrows(int a){
    arrows = a;
}
/*********************************************************************  
** Function: setPlayerX
** Description: Function that sets the playerX to a specific value.
** Parameters: x
*********************************************************************/ 
void Player::setPlayerX(int x){
    playerX = x;
}
/*********************************************************************  
** Function: setPlayerY
** Description: Function that sets the playerY to a specific value.
** Parameters: y
*********************************************************************/ 
void Player::setPlayerY(int y){
    playerY = y;
}
/*********************************************************************  
** Function: setPlayerOriginX
** Description: Function that sets the originPlayerX to a specific value.
** Parameters: x
*********************************************************************/ 
void Player::setPlayerOriginX(int x){
    originPlayerX = x;
}
/*********************************************************************  
** Function: setPlayerOriginY
** Description: Function that sets the originPlayerY to a specific value.
** Parameters: y
*********************************************************************/ 
void Player::setPlayerOriginY(int y){
    originPlayerY = y;
}