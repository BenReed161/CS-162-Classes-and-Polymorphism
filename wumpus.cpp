/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: wumpus.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the wumpus class and handles all the wumpus functionalilty.
*********************************************************************/ 
#include "wumpus.h"
/*********************************************************************  
** Function: Wumpus
** Description: wumpus constructor
*********************************************************************/ 
Wumpus::Wumpus(){

}
/*********************************************************************  
** Function: encounter
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you encounter the specific event
*********************************************************************/ 
void Wumpus::encounter(){
    cout << "As you enter the room, the wumpus runs at you and attacks you. You Die." << endl;
}
/*********************************************************************  
** Function: percieve
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you percieve the specific event
*********************************************************************/ 
void Wumpus::percieve(){
    cout << "You smell a terrible stench." << endl;
}