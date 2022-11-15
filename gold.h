/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: gold.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the gold class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef GOLD_H
#define GOLD_H

#include "event.h"

class Gold : public Event{
    public:
        Gold();
        void encounter();
        void percieve();
};

#endif