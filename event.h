/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: event.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the event class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Event{
    private:

    public:
        Event();
        //Pure virtual functions
        virtual void encounter() = 0;
        virtual void percieve() = 0;
        ~Event();
};

#endif