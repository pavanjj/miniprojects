#include "../headers/gameController.h"
#include "../headers/player.h"
#include "../headers/board.h"
gameState gameController::getGameStatus()
{
    return gameBoard.getGameStatus();
}
bool gameController::getPlayerMove(int playerIdx)
{
    auto cellIdPair = players[playerIdx]->nextMove(gameBoard.getBoard());
    return gameBoard.selectACell(players[playerIdx]->getId(), cellIdPair.first, cellIdPair.second, playerMoveErrorCode);
}
int gameController::getWinnerId()
{
    return gameBoard.getWinnerId();
}
void gameController::initialise()
{
    players[0] = new player(1);
    players[1] = new player(2);
    cout << "Symbol for " << players[0]->getName() << " is " << gameBoard.getSymbol(1) << endl;
    cout << "Symbol for " << players[1]->getName() << " is " << gameBoard.getSymbol(2) << endl;
}
void gameController::startGame()
{
    int curPlayerInternalIdx = 0;
    auto curGameStatus = getGameStatus();
    while (curGameStatus == gameState::ONGOING)
    {
        if (!getPlayerMove(curPlayerInternalIdx))
        {
            switch (playerMoveErrorCode)
            {
            case cellSelectionErrorCodes::CELLOCCUPIED:
                cout << "Selected cell already occupied, select a new one" << endl;
                break;
            case cellSelectionErrorCodes::INVALID_CELL:
                cout << "Invalid Cell, select a new one" << endl;
                break;
            default:
                break;
            }
        }
        else
        {
            curPlayerInternalIdx = (curPlayerInternalIdx + 1) % 2;
            curGameStatus = getGameStatus();
            gameBoard.displayBoard();
        }
    }
    if (curGameStatus == gameState::PLAYERWON)
    {
        players[curPlayerInternalIdx]->updatePlayerStatus(playerState::WON);
        players[(curPlayerInternalIdx + 1) % 2]->updatePlayerStatus(playerState::LOST);
    }
    else if (curGameStatus == gameState::TIED)
    {
        players[curPlayerInternalIdx]->updatePlayerStatus(playerState::DRAWN);
        players[(curPlayerInternalIdx + 1) % 2]->updatePlayerStatus(playerState::DRAWN);
    }
}

void gameController::displayResult()
{
    auto curGameStatus = getGameStatus();
    if (curGameStatus == gameState::PLAYERWON)
    {
        cout << players[getWinnerId() - 1]->getName() << " Won the Game !" << endl;
    }
    else if (curGameStatus == gameState::TIED)
    {
        cout << "Game Tied" << endl;
    }
    else
    {
        cout << "Looks like an unexpected error occurred while playing the game..exiting" << endl;
    }
}
gameController::~gameController()
{
    free(players[0]);
    free(players[1]);
}