#include <vector>
using namespace std;
#include <./gameState.h>
#include <iostream>
#define BOARD_SIZE 3
#define UNKNOWN -1
class Board
{
    vector<vector<int>> cells;
    vector<int> rowSums;
    vector<int> colSums;
    int winnerId;
    int unoccupied;
    gameState status;
    void setWinnerId(int pId);
    void updateGameStatus(int pId, int row, int col);
    void setGameStatus(gameState gameStatus);

public:
    Board()
    {
        cells = vector<vector<int>>(BOARD_SIZE, vector<int>(BOARD_SIZE, UNOCCUPIED));
        unoccupied = BOARD_SIZE * BOARD_SIZE;
        winnerId = UNKNOWN;
        status = ONGOING;
        rowSums = vector<int>(BOARD_SIZE, 0);
        colSums = vector<int>(BOARD_SIZE, 0);
    }
    const vector<vector<int>> &getBoard();
    bool selectACell(int pId, int row, int col);
    gameState getGameStatus();
    int getWinnerId();
    void resetBoard();
};
