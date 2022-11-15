/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: gold.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the gold class and handles all the wumpus functionalilty.
*********************************************************************/ 
#include "gold.h"
/*********************************************************************  
** Function: Gold
** Description: Gold constructor
*********************************************************************/ 
Gold::Gold(){

}
/*********************************************************************  
** Function: encounter
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you encounter the specific event
*********************************************************************/
void Gold::encounter(){
    cout << "You find the gold." << endl;
}
/*********************************************************************  
** Function: percieve
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you percieve the specific event
*********************************************************************/
void Gold::percieve(){
    cout << "You see a glimmer nearby." << endl;
}