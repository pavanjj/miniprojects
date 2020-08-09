#include <./player.h>
#include <./gameState.h>
class gameController
{
    player players[2];
    Board gameBoard;

public:
    void initialise();
    void startGame();
    gameState getGameStatus();
    int getPlayerMove(int pId);
    int getWinnerId();
};