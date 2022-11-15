/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: driver.cpp
** Author: Ben Reed
** Date: 5/22/2021
** Description: This is the driver file that takes in the file input of the
user and starts the game.
*********************************************************************/ 
#include "game.h"
/*********************************************************************  
** Function: errorCheck
** Description: This function makes sure that the user doesn't enter incorrect
information when creating the grid, it can't be less than 4. It also must be
t and f after it. 
** Parameters: size and debug
** Post-Conditions: returns true if the debug mode is true, and false otherwise
*********************************************************************/ 
bool errorCheck(int size, char debug){
    if(size < 4){
        cout << "First arguement must be at least 4." << endl;
        exit(EXIT_FAILURE);
    }
    else{
        cout << "Grid-Size: " << size << endl;
    }
    if((debug == 'F') || (debug == 'T') || (debug == 't') || (debug == 'f')){
        if((debug == 'T') || (debug == 't')){
            cout << "Debug Mode: True" << endl;
            return true;
        } 
        if((debug == 'F') || (debug == 'f')){
            cout << "Debug Mode: False" << endl;
            return false;
        }
    }
    else{
        cout << "Second arguement must be a T or F. (Case doesn't matter.)" << endl;
        exit(EXIT_FAILURE);
    }
}
/*********************************************************************  
** Function: main
** Description: This function takes in the command line args from the user
and calls the errorCheck function to make sure the infomation entered is 
correct.
** Parameters: argc, argv[]
*********************************************************************/ 
int main(int argc, char *argv[]){
    bool debug = errorCheck(atoi(argv[1]), *(argv[2]));
    int gridSize = atoi(argv[1]);
    Game g1;
    g1.startGame(gridSize, debug);
}