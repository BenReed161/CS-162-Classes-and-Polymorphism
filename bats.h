/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: bats.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the bats class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef BAT_H
#define BAT_H

#include "event.h"

class Bats : public Event{
    public:
        Bats();
        void encounter();
        void percieve();
};

#endif