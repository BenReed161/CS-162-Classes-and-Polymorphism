/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: room.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the room class and handles all the room functionalilty.
*********************************************************************/ 
#include "room.h"
/*********************************************************************  
** Function: Room
** Description: Room constructor
*********************************************************************/
Room::Room(){
    isEmpty = true;
}
/*********************************************************************  
** Function: empty
** Description: Sets the room to empty
** Parameters: val
*********************************************************************/
void Room::empty(bool val){
    isEmpty = val;
}
/*********************************************************************  
** Function: getEmpty
** Description: returns the isEmpty bool 
** Post-Conditions: returns bool
*********************************************************************/
bool Room::getEmpty(){
    return isEmpty;
}
/*********************************************************************  
** Function: getStart
** Description: returns the isStart bool
** Post-Conditions: returns bool
*********************************************************************/
bool Room::getStart(){
    return isStart;
}
/*********************************************************************  
** Function: start
** Description: sets the start bool to the val bool
** Parameters: val
*********************************************************************/
void Room::start(bool val){
    isStart = val;
}
/*********************************************************************  
** Function: getWumpusNum
** Description: returns wumpusNum
** Post-Conditions: return int
*********************************************************************/
int Room::getWumpusNum(){
    return wumpusNum;
}
/*********************************************************************  
** Function: getGoldNum
** Description: returns getGoldNum
** Post-Conditions: return int
*********************************************************************/
int Room::getGoldNum(){
    return goldNum;
}
/*********************************************************************  
** Function: getBatsNum
** Description: returns getBatsNum
** Post-Conditions: return int
*********************************************************************/
int Room::getBatsNum(){
    return batNum;
}
/*********************************************************************  
** Function: getPitNum
** Description: returns getPitNum
** Post-Conditions: return int
*********************************************************************/
int Room::getPitNum(){
    return pitNum;
}
/*********************************************************************  
** Function: getPlayerNum
** Description: returns getPlayerNum
** Post-Conditions: return int
*********************************************************************/
int Room::getPlayerNum(){
    return playerNum;
}
/*********************************************************************  
** Function: fillWumpus
** Description: increments the wumpusNum
** Post-Conditions: wumpusNum ++ 
*********************************************************************/
void Room::fillWumpus(){
    wumpusNum++;
}
/*********************************************************************  
** Function: fillGold
** Description: increments the goldNum
** Post-Conditions: goldNum ++ 
*********************************************************************/
void Room::fillGold(){
    goldNum++;
}
/*********************************************************************  
** Function: fillBats
** Description: increments the batNum
** Post-Conditions: batNum ++ 
*********************************************************************/
void Room::fillBats(){
    batNum++;
}
/*********************************************************************  
** Function: fillPit
** Description: increments the pitNum
** Post-Conditions: pitNum ++ 
*********************************************************************/
void Room::fillPit(){
    pitNum++;
}
/*********************************************************************  
** Function: fillPlayer
** Description: increments the playerNum
** Post-Conditions: playerNum ++ 
*********************************************************************/
void Room::fillPlayer(){
    playerNum++;
}
/*********************************************************************  
** Function: removePlayer
** Description: decrements the playerNum
** Post-Conditions: playerNum --
*********************************************************************/
void Room::removePlayer(){
    playerNum--;
}
/*********************************************************************  
** Function: removeGold
** Description: decrements the goldNum
** Post-Conditions: goldNum --
*********************************************************************/
void Room::removeGold(){
    goldNum--;
}
/*********************************************************************  
** Function: removeWumpus
** Description: decrements the wumpusNum
** Post-Conditions: wumpusNum --
*********************************************************************/
void Room::removeWumpus(){
    wumpusNum--;
}
/*********************************************************************  
** Function: removeBats
** Description: decrements the batNum
** Post-Conditions: batNum --
*********************************************************************/
void Room::removeBats(){
    batNum--;
}
/*********************************************************************  
** Function: removePit
** Description: decrements the pitNum
** Post-Conditions: pitNum --
*********************************************************************/
void Room::removePit(){
    pitNum--;
}

/*********************************************************************  
** Function: checkRoom
** Description: returns what's inside the room
** Post-Conditions: returns an int from 0 to 4
*********************************************************************/
int Room::checkRoom(){
    if(wumpusNum == 1){
        return 1;
    }
    if(goldNum == 1){
        return 2;
    }
    if(batNum == 1){
        return 3;
    }
    if(pitNum == 1){
        return 4;
    }
    return 0;
}
/*********************************************************************  
** Function: returnWumpus
** Description: returns an event pointer that is pointing to a wumpus object.
** Post-Conditions: return *Event
*********************************************************************/
Event * Room::returnWumpus(){
    return event1;
}
/*********************************************************************  
** Function: returnGold
** Description: returns an event pointer that is pointing to a gold object.
** Post-Conditions: return *Event
*********************************************************************/
Event * Room::returnGold(){
    return event2;
}
/*********************************************************************  
** Function: returnBats
** Description: returns an event pointer that is pointing to a bat object.
** Post-Conditions: return *Event
*********************************************************************/
Event * Room::returnBats(){
    return event3;
}
/*********************************************************************  
** Function: returnPit
** Description: returns an event pointer that is pointing to a pit object.
** Post-Conditions: return *Event
*********************************************************************/
Event * Room::returnPit(){
    return event4;
}