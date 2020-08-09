#include <./headers/gameController.h>
#include <./headers/player.h>
#include <./board.h>
gameState gameController::getGameStatus()
{
    return gameBoard.getGameStatus();
}
int gameController::getPlayerMove(int playerIdx)
{
    auto cellIdPair = players[playerIdx].nextMove(gameBoard.getBoard());
    gameBoard.selectACell(players[playerIdx].getId(), cellIdPair.first, cellIdPair.second);
}
int gameController::getWinnerId()
{
    return gameBoard.getWinnerId();
}
void gameController::initialise()
{
    players[0] = player(1);
    players[1] = player(2);
    gameBoard = Board();
}
void gameController::startGame()
{
    int curPlayerInternalIdx = 0;
    auto curGameStatus = getGameStatus();
    while (curGameStatus == ONGOING)
    {
        getPlayerMove(curPlayerInternalIdx);
        curPlayerInternalIdx = (curPlayerInternalIdx + 1) % 2;
        curGameStatus = getGameStatus();
    }
    if (curGameStatus == PLAYERWON)
    {
        cout << "Player " << getWinnerId() << " won the game !" << endl;
        setPlayerStatus();
    }
    else
    {
        cout << "Game Tied" << endl;
    }
}