/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: pit.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the pit class and handles all the wumpus functionalilty.
*********************************************************************/ 
#include "pit.h"
/*********************************************************************  
** Function: Pit
** Description: Pit constructor
*********************************************************************/ 
Pit::Pit(){

}
/*********************************************************************  
** Function: encounter
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you encounter the specific event
*********************************************************************/
void Pit::encounter(){
    cout << "You slip as you enter the room, and fall into a bottomless pit. You Die." << endl;
}
/*********************************************************************  
** Function: percieve
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you percieve the specific event
*********************************************************************/
void Pit::percieve(){
    cout << "You feel a breeze." << endl;
} 