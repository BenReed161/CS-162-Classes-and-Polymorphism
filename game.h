/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: game.h
** Author: Ben Reed
** Date: 5/22/2021
** Description: This is the game class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <time.h>
#include "room.h"
#include "player.h"

using namespace std;

class Game{
    private:
        Player player;
        vector<vector<Room>> rooms;
        //Origin points so when the player resets same room the wumpus/gold goes back
        int wumpusOriginX = 0;
        int wumpusOriginY = 0;
        int wumpusX = 0;
        int wumpusY = 0;
        int goldOriginX = 0;
        int goldOriginY = 0;

        int numWumpus = 0;
        int numGold = 0;
        int numPit = 0;
        int numBats = 0;
    public:
        Game();
        void roomResize(int);

        void startGame(int, bool);
        void replay(int);
        void resetRoom(int);
        void sameRoom(int);
        void playerTurn(int, bool);
        bool winCondition(int);

        void fillRooms(int);

        void drawGrid(int, bool);
        void drawDebug(int, int, bool);

        void detectEvents(int);
        int searchEvents(int);

        void printInfo(int, int, int);

        int placePlayer(int);
        void shoot(int, int, bool);
        int moveWumpus(int);
        bool oob(int,int,int);
};

#endif