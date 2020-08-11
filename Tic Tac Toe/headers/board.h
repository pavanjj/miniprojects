#ifndef BOARD
#define BOARD
#include <vector>
using namespace std;
#include "gameState.h"
#include <iostream>
#define BOARD_SIZE 3
#define UNKNOWN -1
class Board
{
    vector<vector<int>> cells;
    vector<int> rowSums;
    vector<int> colSums;
    int weights[2];
    int diagSum;
    int crossDiagSum;
    int winnerId;
    int unoccupied;
    gameState status;
    void setWinnerId(int pId);
    void updateGameStatus(int pId, int row, int col);
    void setGameStatus(gameState gameStatus);
    char symbol[2];

public:
    Board()
    {
        cells = vector<vector<int>>(BOARD_SIZE, vector<int>(BOARD_SIZE, UNOCCUPIED));
        unoccupied = BOARD_SIZE * BOARD_SIZE;
        winnerId = UNKNOWN;
        status = gameState::ONGOING;
        rowSums = vector<int>(BOARD_SIZE, 0);
        colSums = vector<int>(BOARD_SIZE, 0);
        crossDiagSum = 0;
        diagSum = 0;
        weights[0] = 1;
        weights[1] = 4;
        symbol[0] = 'O';
        symbol[1] = 'X';
    }
    char getSymbol(int playerId);
    void displayBoard();
    const vector<vector<int>> &getBoard();
    bool selectACell(int pId, int row, int col, cellSelectionErrorCodes &errorCode);
    gameState getGameStatus();
    int getWinnerId();
    void resetBoard();
};
#endif