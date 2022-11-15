/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: player.h
** Author: Ben Reed
** Date: 5/21/2021
** Description: This is the player class, and includes all the function
and member variables related to the class.
*********************************************************************/ 
#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
        int originPlayerX;
        int originPlayerY;
        int arrows;
        int playerX;
        int playerY;
        bool hasGold;
    public:
        Player();
        void gold(bool);
        bool returnGold();
        int getPlayerX();
        int getPlayerY();
        int getArrows();
        int getPlayerOriginX();
        int getPlayerOriginY();
        void removeArrow();
        void setArrows(int);

        void setPlayerX(int);
        void setPlayerY(int);
        void setPlayerOriginX(int);
        void setPlayerOriginY(int);
};

#endif