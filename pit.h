/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: pit.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the pit class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit : public Event{
    public:
        Pit();
        void encounter();
        void percieve();
};

#endif