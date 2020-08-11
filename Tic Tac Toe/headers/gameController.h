#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER
#include "player.h"
#include "gameState.h"
#include "board.h"

class gameController
{
    player *players[2];
    Board gameBoard;

public:
    cellSelectionErrorCodes playerMoveErrorCode;
    void initialise();
    void startGame();
    gameState getGameStatus();
    bool getPlayerMove(int pId);
    int getWinnerId();
    void displayResult();
    ~gameController();
};
#endif