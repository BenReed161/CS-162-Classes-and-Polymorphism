/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: wumpus.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the wumpus class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

class Wumpus : public Event{
    private:
        int originWumpusX = 0;
        int originWumpusY = 0;
    public:
        Wumpus();
        void encounter();
        void percieve();
};

#endif