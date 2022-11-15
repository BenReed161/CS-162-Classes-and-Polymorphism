/*********************************************************************  
** Program: Hunt the Wumpus
** Filename: game.cpp
** Author: Ben Reed
** Date: 5/22/2021
** Description: This is the file that contains all the function definitions
for the game class and handles all the player turns and game logic.
*********************************************************************/ 
#include "game.h"
//Macros used for ease of typing when creating colored console messages
#define WHITE "\033[37;47m"
#define MAGENTA "\033[37;45m"
#define BLACK "\033[37;40m"
#define YELLOW "\033[30;43m"
#define RED "\033[37;41m"
#define CYAN "\033[30;46m"
#define BOLDRED "\033[1m\033[31m"
#define RESET "\033[0m"
/*********************************************************************  
** Function: Game
** Description: Game constructor.
*********************************************************************/ 
Game::Game(){

}
/*********************************************************************  
** Function: roomResize
** Description: Function that resizes the vector to the size of the room
specificied by the user.
** Parameters: size 
*********************************************************************/ 
void Game::roomResize(int size){
    rooms.resize(size);
    for (int i = 0; i < size; ++i){
        rooms[i].resize(size);
    }
}
/*********************************************************************  
** Function: startGame
** Description: Main function where all the functions branch from
starts the game and initializes all the variables.
** Parameters: size, debug
*********************************************************************/ 
void Game::startGame(int size, bool debug){
    player.gold(false);
    int eventNum = 0;
    cout << BOLDRED << "The hunt is about to begin..." << RESET << endl;
    roomResize(size);
    fillRooms(size);
    placePlayer(size);
    player.setPlayerOriginX(player.getPlayerX());
    player.setPlayerOriginY(player.getPlayerY());
    rooms.at(player.getPlayerX()).at(player.getPlayerY()).start(true);
    while(true){
        eventNum = searchEvents(size);
        if(eventNum == 1 || eventNum == 4){
            replay(size);
        }
        if(eventNum == 3){
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            placePlayer(size);
        }
        drawGrid(size, debug);
        detectEvents(size);
        playerTurn(size, debug);
        if(winCondition(size)){
            player.gold(false);
            cout << "You escaped with the gold! You Win!" << endl;
            replay(size);
        }
    }
}
/*********************************************************************  
** Function: replay
** Description: This function is called when the player loses/ or wins
** Parameters: size 
*********************************************************************/ 
void Game::replay(int size){
    int playerChoice1 = 0;
    int playerChoice2 = 0;
    cout << "Would you like to play again? (1: yes, 2: no): " << endl;
    cin >> playerChoice1;
    if(playerChoice1 == 1){
        cout << "Would you like to play with the same layout or different? (1: same, 2: different): " << endl;
        cin >> playerChoice2;
        if(playerChoice2 == 1){
            player.setArrows(4);
            sameRoom(size);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            rooms.at(player.getPlayerOriginX()).at(player.getPlayerOriginY()).empty(false);
            rooms.at(player.getPlayerOriginX()).at(player.getPlayerOriginY()).fillPlayer();
            player.setPlayerX(player.getPlayerOriginX());
            player.setPlayerY(player.getPlayerOriginY());
            player.setPlayerOriginX(player.getPlayerOriginX());
            player.setPlayerOriginY(player.getPlayerOriginY());
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).start(true);
            player.gold(false);
        }
        else if(playerChoice2 == 2){
            player.setArrows(4);
            resetRoom(size);
            fillRooms(size);
            placePlayer(size);
            player.setPlayerOriginX(player.getPlayerX());
            player.setPlayerOriginY(player.getPlayerY());
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).start(true);
        }
    }
    else if(playerChoice1 == 2){
        for (int k = 0; k < rooms.size(); ++k){     
            rooms[k].clear();
            rooms[k].shrink_to_fit();   
        }
        rooms.clear();
        rooms.shrink_to_fit();
        exit(EXIT_SUCCESS);
    }
}
/*********************************************************************  
** Function: resetRoom
** Description: This function resets the vector when the user wants to
play again with a different room
** Parameters: size 
*********************************************************************/ 
void Game::resetRoom(int size){
    numBats = 0;
    numWumpus = 0;
    numPit = 0;
    numGold = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            rooms.at(i).at(j).empty(true);
            rooms.at(i).at(j).start(false);
            if(rooms.at(i).at(j).getWumpusNum() == 1){
                rooms.at(i).at(j).removeWumpus();
            }
            if(rooms.at(i).at(j).getGoldNum() == 1){
                rooms.at(i).at(j).removeGold();
            }
            if(rooms.at(i).at(j).getBatsNum() == 1){
                rooms.at(i).at(j).removeBats();
            }
            if(rooms.at(i).at(j).getPitNum() == 1){
                rooms.at(i).at(j).removePit();
            }
            if(rooms.at(i).at(j).getPlayerNum() == 1){
                rooms.at(i).at(j).removePlayer();
            }
        }
    }    
}
/*********************************************************************  
** Function: sameRoom
** Description: Function that sets the room back to the same spot when
the user wants to play again.
** Parameters: size
*********************************************************************/ 
void Game::sameRoom(int size){
    if(rooms.at(wumpusX).at(wumpusY).getWumpusNum() == 1 && rooms.at(wumpusX).at(wumpusY).getEmpty() == false){
        rooms.at(wumpusX).at(wumpusY).removeWumpus();
        rooms.at(wumpusX).at(wumpusY).empty(true);
    }
    wumpusX = wumpusOriginX;
    wumpusY = wumpusOriginY;
    rooms.at(wumpusOriginX).at(wumpusOriginY).fillWumpus();
    rooms.at(wumpusOriginX).at(wumpusOriginY).empty(false);
    if(rooms.at(goldOriginX).at(goldOriginY).getGoldNum() == 0 && rooms.at(goldOriginX).at(goldOriginY).getEmpty() == true){
        rooms.at(goldOriginX).at(goldOriginY).empty(false);
        rooms.at(goldOriginX).at(goldOriginY).fillGold();
    }
    
}
/*********************************************************************  
** Function: playerTurn
** Description: Function is called when the player makes their turn, and
accepts inputs from the user and makes sure it's not out of bounds.
** Parameters: size, debug
*********************************************************************/ 
void Game::playerTurn(int size, bool debug){
    string turnInput;
    while(true){
        cout << "To move type (W,A,S,D) and to shoot type a \".\" before (W,A,S,D)." << endl;
        cin >> turnInput;
        if(turnInput == ".W"){
            shoot(size, 1, debug);
        }
        else if(turnInput == ".D"){
            shoot(size, 2, debug);
        }
        else if(turnInput == ".S"){
            shoot(size, 3, debug);
        }
        else if(turnInput == ".A"){
            shoot(size, 4, debug);
        }
        else if(turnInput == "W" && (oob(size, player.getPlayerX()-1, player.getPlayerY()))){
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(true);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            player.setPlayerX(player.getPlayerX()-1);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(false);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).fillPlayer();
            break;
        }
        else if(turnInput == "S" && (oob(size, player.getPlayerX()+1, player.getPlayerY()))){
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(true);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            player.setPlayerX(player.getPlayerX()+1);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(false);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).fillPlayer();
            break;
        }
        else if(turnInput == "D" && (oob(size, player.getPlayerX(), player.getPlayerY()+1))){
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(true);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            player.setPlayerY(player.getPlayerY()+1);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(false);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).fillPlayer();
            break;
        }
        else if(turnInput == "A" && (oob(size, player.getPlayerX(), player.getPlayerY()-1))){
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(true);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).removePlayer();
            player.setPlayerY(player.getPlayerY()-1);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).empty(false);
            rooms.at(player.getPlayerX()).at(player.getPlayerY()).fillPlayer();
            break;
        }
        else{
            cout << "While trying to move you stumble into a wall.(Try a different direction)" << endl;
        }
    }
}
/*********************************************************************  
** Function: winCondition
** Description: Frunction that returns if the player wins in the game, and
is on top of the start location with the gold.
** Parameters: size
** Post-Conditions: return true, return false
*********************************************************************/ 
bool Game::winCondition(int size){
    if((player.getPlayerX() == player.getPlayerOriginX()) && (player.getPlayerY() == player.getPlayerOriginY()) && (player.returnGold() == true)){
        return true;
    }
    else{
        return false;
    }
}
/*********************************************************************  
** Function: fillRooms
** Description: Function that fill the vector with the correct type of event
ensures that events cannot occur more times than they should
** Parameters: size
*********************************************************************/ 
void Game::fillRooms(int size){
    srand(time(NULL));
    int randomEvent;
    while (numWumpus == 0 || numGold == 0){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                randomEvent = rand() % 5 + 1;
                if(randomEvent == 1 && numWumpus == 0 && rooms.at(i).at(j).getEmpty() == true){
                    numWumpus++;
                    wumpusOriginX = i;
                    wumpusOriginY = j;
                    wumpusX = i;
                    wumpusY = j;
                    rooms.at(i).at(j).fillWumpus();
                    rooms.at(i).at(j).empty(false);
                }
                if(randomEvent == 2 && numGold == 0 && rooms.at(i).at(j).getEmpty() == true){
                    numGold++;
                    goldOriginX = i;
                    goldOriginY = j;
                    rooms.at(i).at(j).fillGold();
                    rooms.at(i).at(j).empty(false);
                }
            }
        }
    }
    while (numPit < 2 || numBats < 2){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                randomEvent = rand() % 5 + 1;
                if(randomEvent == 1 && numPit < 2 && rooms.at(i).at(j).getEmpty() == true){ 
                    numPit++;
                    rooms.at(i).at(j).fillPit();
                    rooms.at(i).at(j).empty(false);
                }
                if(randomEvent == 2 && numBats < 2 && rooms.at(i).at(j).getEmpty() == true){
                    numBats++;
                    rooms.at(i).at(j).fillBats();
                    rooms.at(i).at(j).empty(false);
                }
            }
        }
    }
}
/*********************************************************************  
** Function: drawGrid
** Description: Function that prints out the grid to the screen using 
Linux color codes.
** Parameters: size debug
*********************************************************************/ 
void Game::drawGrid(int size, bool debug){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << WHITE << "0000";
        }
        cout << "0";
        cout << RESET;
        cout << endl;
        for(int j = 0; j < size; j++){
            cout << WHITE << "0" << RESET << "?";
            drawDebug(i,j,debug);
            cout << RESET;
            cout << "?" << WHITE;
        }
        cout << "0";
        cout << RESET;
        cout << endl;
    }
    for(int j = 0; j < size; j++){
        cout << WHITE << "0000";
    }
    cout << "0";
    cout << RESET;
    cout << endl;
}
/*********************************************************************  
** Function: drawDebug
** Description: Function that draws the symbols for each of the events if
debug mode is enabled.
** Parameters: i, j, debug
*********************************************************************/ 
void Game::drawDebug(int i, int j, bool debug){
    if(rooms.at(i).at(j).getEmpty() == false && rooms.at(i).at(j).getPlayerNum() == 1){
        cout << CYAN << "*";
    }
    else if(rooms.at(i).at(j).getEmpty() == false && debug == true){
        if(rooms.at(i).at(j).checkRoom() == 1)
            cout << RED << "W";
        if(rooms.at(i).at(j).checkRoom() == 2)
            cout << YELLOW << "G";
        if(rooms.at(i).at(j).checkRoom() == 3)
            cout << MAGENTA << "B";
        if(rooms.at(i).at(j).checkRoom() == 4)
            cout << BLACK << "P";
    }
    else if(rooms.at(i).at(j).getStart() == true && debug == true){
        cout << CYAN << "S";
    }
    else if(rooms.at(i).at(j).getEmpty() == true || debug == false && rooms.at(i).at(j).getPlayerNum() == 0){
        cout << RESET << "?";
    }
}
/*********************************************************************  
** Function: detectEvents
** Description: Function that goes around clockwise around the player and
determines what's around them and prints it out to the screen using the 
printInfo function.
** Parameters: size 
*********************************************************************/ 
void Game::detectEvents(int size){
    if(oob(size, player.getPlayerX()+1, player.getPlayerY())){
        printInfo(size, 1, 0);
    }
    if(oob(size, (player.getPlayerX()-1), player.getPlayerY())){
        printInfo(size, -1, 0);
    }
    if(oob(size, player.getPlayerX(), player.getPlayerY()-1)){
        printInfo(size, 0, -1);
    }
    if(oob(size, player.getPlayerX(), player.getPlayerY()+1)){
        printInfo(size, 0, 1);
    }
}
/*********************************************************************  
** Function: searchEvents
** Description: Function that prints the encounter information when a
player enters into that room, and uses the abstract encounter function
** Parameters: size
*********************************************************************/ 
int Game::searchEvents(int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(rooms.at(i).at(j).checkRoom() != 0 && rooms.at(i).at(j).getPlayerNum() == 1){
                if(rooms.at(i).at(j).checkRoom() == 1){
                    rooms.at(i).at(j).returnWumpus()->encounter();
                    return 1;
                }
                if(rooms.at(i).at(j).checkRoom() == 2){
                    rooms.at(i).at(j).returnGold()->encounter();
                    player.gold(true);
                    rooms.at(i).at(j).removeGold();
                    return 2;
                }
                if(rooms.at(i).at(j).checkRoom() == 3){
                    rooms.at(i).at(j).returnBats()->encounter();
                    return 3;
                }
                if(rooms.at(i).at(j).checkRoom() == 4){
                    rooms.at(i).at(j).returnPit()->encounter();
                    return 4;
                }
            }
        }
    }
    return 0;
}
/*********************************************************************  
** Function: printInfo
** Description: Function that calls the return functions that return
event pointers that point to the references of each of the events, then the
abstarct perieve function is called.
** Parameters: size x y
*********************************************************************/ 
void Game::printInfo(int size, int x, int y){
    if(rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).checkRoom() == 1){
        rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).returnWumpus()->percieve();
    }
    if(rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).checkRoom() == 2){
        rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).returnGold()->percieve();
    }
    if(rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).checkRoom() == 3){
        rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).returnBats()->percieve();       
    }
    if(rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).checkRoom() == 4){
        rooms.at(player.getPlayerX()+x).at(player.getPlayerY()+y).returnPit()->percieve();
    }
}
/*********************************************************************  
** Function: placePlayer
** Description: Function that randomly places the player in a spot where
they can go without overlapping another full room.
** Parameters: size 
*********************************************************************/ 
int Game::placePlayer(int size){
    srand(time(NULL));
    int randomEvent;
    while (true){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                randomEvent = rand() % 5 + 1;
                if(randomEvent == 1 && rooms.at(i).at(j).getEmpty() == true){
                    rooms.at(i).at(j).empty(false);
                    rooms.at(i).at(j).fillPlayer();
                    player.setPlayerX(i);
                    player.setPlayerY(j);
                    return 0;
                }  
            }
        }
    }    
}
/*********************************************************************  
** Function: shoot
** Description: Function that shoots arrows for the player, tells them
if they are out of arrows and prints when they hit the wumpus.
** Parameters: size diection debug
*********************************************************************/ 
void Game::shoot(int size, int direction, bool debug){
    bool missed = false;
    if(player.getArrows() <= -1){
        cout << "You're out of arrows!" << endl;
    }
    if(direction == 1 && player.getArrows() >= 0){
        player.removeArrow();
        for(int i = player.getPlayerX(); i >= 0; i--){
            if(rooms.at(i).at(player.getPlayerY()).getWumpusNum() == 1){
                cout << "Wumpus shot!" << endl;
                rooms.at(i).at(player.getPlayerY()).removeWumpus();
                rooms.at(i).at(player.getPlayerY()).empty(true);
                missed = false;
                break;
            }
            else{
                missed = true;
            }
        }
    }
    if(direction == 2 && player.getArrows() >= 0){
        player.removeArrow();
        for(int i = player.getPlayerY(); i < size; i++){
            if(rooms.at(player.getPlayerX()).at(i).getWumpusNum() == 1){
                cout << "Wumpus shot!" << endl;
                rooms.at(player.getPlayerX()).at(i).removeWumpus();
                rooms.at(player.getPlayerX()).at(i).empty(true);
                missed = false;
                break;
            }
            else{
                missed = true;
            }
        }
    }
    if(direction == 3 && player.getArrows() >= 0){
        player.removeArrow();
        for(int i = player.getPlayerX(); i < size; i++){
            if(rooms.at(i).at(player.getPlayerY()).getWumpusNum() == 1){
                cout << "Wumpus shot!" << endl;
                rooms.at(i).at(player.getPlayerY()).removeWumpus();
                rooms.at(i).at(player.getPlayerY()).empty(true);
                missed = false;
                break;
            }
            else{
                missed = true;
            }
        }
    }
    if(direction == 4 && player.getArrows() > 0){
        player.removeArrow();
        for(int i = player.getPlayerY(); i >= 0; i--){
            if(rooms.at(player.getPlayerX()).at(i).getWumpusNum() == 1){
                cout << "Wumpus shot!" << endl;
                rooms.at(player.getPlayerX()).at(i).removeWumpus();
                rooms.at(player.getPlayerX()).at(i).empty(true);
                missed = false;
                break;
            }
            else{
                missed = true;
            }
        }
    }
    if(missed == true){
        player.removeArrow();
        cout << "You fire your bow and miss!" << endl;
        moveWumpus(size);
    }
    drawGrid(size, debug);
}
/*********************************************************************  
** Function: moveWumpus
** Description: When the user misses a shot this function will be called
and the wumpus will randomly move, will only happen 75% of the time.
** Parameters: size 
*********************************************************************/ 
int Game::moveWumpus(int size){
    srand (time(NULL));
    int moveRand = rand() % 100;
    if(moveRand >= 25 && moveRand <= 100){
        if(oob(size, wumpusX+1, wumpusY) && rooms.at(wumpusX+1).at(wumpusY).getEmpty() == true && rooms.at(wumpusX+1).at(wumpusY).getStart() == false){
            cout << "You hear the sound of steps as the wumpus moves around the cave.." << endl;
            rooms.at(wumpusX).at(wumpusY).empty(true);
            rooms.at(wumpusX).at(wumpusY).removeWumpus();
            rooms.at(wumpusX+1).at(wumpusY).fillWumpus();
            rooms.at(wumpusX+1).at(wumpusY).empty(false);
            wumpusX+=1;
            return 0;
        }
        if(oob(size, wumpusX-1, wumpusY) && rooms.at(wumpusX-1).at(wumpusY).getEmpty() == true && rooms.at(wumpusX-1).at(wumpusY).getStart() == false){
            cout << "You hear the sound of steps as the wumpus moves around the cave.." << endl;
            rooms.at(wumpusX).at(wumpusY).empty(true);
            rooms.at(wumpusX).at(wumpusY).removeWumpus();
            rooms.at(wumpusX-1).at(wumpusY).fillWumpus();
            rooms.at(wumpusX-1).at(wumpusY).empty(false);
            wumpusX-=1;
            return 0;
        }
        if(oob(size,  wumpusX, wumpusY-1) && rooms.at(wumpusX).at(wumpusY-1).getEmpty() == true && rooms.at(wumpusX).at(wumpusY-1).getStart() == false){
            cout << "You hear the sound of steps as the wumpus moves around the cave.." << endl;
            rooms.at(wumpusX).at(wumpusY).empty(true);
            rooms.at(wumpusX).at(wumpusY).removeWumpus();
            rooms.at(wumpusX).at(wumpusY-1).fillWumpus();
            rooms.at(wumpusX).at(wumpusY-1).empty(false);
            wumpusY-=1;
            return 0;
        }
        if(oob(size, wumpusX, wumpusY+1) && rooms.at(wumpusX).at(wumpusY+1).getEmpty() == true && rooms.at(wumpusX).at(wumpusY+1).getStart() == false){
            cout << "You hear the sound of steps as the wumpus moves around the cave.." << endl;
            rooms.at(wumpusX).at(wumpusY).empty(true);
            rooms.at(wumpusX).at(wumpusY).removeWumpus();
            rooms.at(wumpusX).at(wumpusY+1).fillWumpus();
            rooms.at(wumpusX).at(wumpusY+1).empty(false);
            wumpusY+=1;
            return 0;
        }
    }
}
/*********************************************************************  
** Function: oob
** Description: oob, short hand for Out of Bounds, will detect when anything
in the game has made an illegal move out of the bounds of the vector and correct
it.
** Parameters: size boundX boundY
** Post-Conditions: return true, returns false
*********************************************************************/ 
bool Game::oob(int size, int boundX, int boundY){
    size = size - 1;
    if((boundX > size || boundX < 0) || (boundY > size || boundY < 0)){
        return false;
    }
    if((boundX <= size && boundX >= 0) && (boundY <= size && boundY >= 0)){
        return true;
    }
}