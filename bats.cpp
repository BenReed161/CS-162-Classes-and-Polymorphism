/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: bats.cpp
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the file that contains all the function definitions
for the bats class and handles all the wumpus functionalilty.
*********************************************************************/ 
#include "bats.h"
/*********************************************************************  
** Function: Bats
** Description: Bats constructor
*********************************************************************/ 
Bats::Bats(){

}
/*********************************************************************  
** Function: encounter
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you encounter the specific event
*********************************************************************/
void Bats::encounter(){
    cout << "A cloud of Super Bats picks up and places you in a random room." << endl;
}
/*********************************************************************  
** Function: percieve
** Description: Overwritten function that is used by all the functions
that inherit from the Event class, pure virtual that is defined in the
Event class. Prints what happens when you percieve the specific event
*********************************************************************/
void Bats::percieve(){
    cout << "You hear wings flapping." << endl;
} 