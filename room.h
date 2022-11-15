/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: room.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the room class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"

class Room{
    private:
        bool isEmpty;
        bool isStart;
        int playerNum = 0;
        int wumpusNum = 0;
        int goldNum = 0;
        int batNum = 0;
        int pitNum = 0;
        /////////////////////////////////////////////////////////////////////////////////////////
        /*
        Note:
        I realized too late that these member varibles should not be included, but I
        had already put in 5 days of working on the project and all my code was working
        around having these member variables in the room class. These member varibles
        are only used to be put passed by reference and then stored in the event pointers.
        To keep in spirit with the projects polymorphism, I converted them to event pointers
        so that the event pointers can be used with the pure virtual functions. I would
        understand if this is not allowed but I couldn't find a way around this problem without
        scrapping a large portion of my program and recoding it, and potentially going over
        alotted time. I still however incorperated Polymorphism into the project with an
        abstract Event class, and Event pointers calling the virtual functions.
        */
        //Explicitly used here only.
        Wumpus w;
        Gold g;
        Bats b;
        Pit p;
        /////////////////////////////////////////////////////////////////////////////////////////
        //Converted to Event pointers.
        Event *event1 = &(w);
        Event *event2 = &(g);
        Event *event3 = &(b);
        Event *event4 = &(p);
        /////////////////////////////////////////////////////////////////////////////////////////
    public:
        Room();
        
        void empty(bool);
        bool getEmpty();
        void start(bool);
        bool getStart();

        int getWumpusNum();
        int getGoldNum();
        int getBatsNum();
        int getPitNum();
        int getPlayerNum();

        void fillWumpus();
        void fillGold();
        void fillBats();
        void fillPit();
        void fillPlayer();

        void removePlayer();
        void removeGold();
        void removeWumpus();
        void removeBats();
        void removePit();

        int checkRoom();
        Event * returnWumpus();
        Event * returnGold();
        Event * returnBats();
        Event * returnPit();
};

#endif