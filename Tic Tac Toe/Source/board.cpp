#include "../headers/board.h"

const vector<vector<int>> &Board ::getBoard()
{
    return cells;
}

void Board::updateGameStatus(int pId, int row, int col)
{
    int weight = weights[pId - 1];
    rowSums[row] += weight;
    colSums[col] += weight;
    if (row == col)
        diagSum += weight;
    if (row == BOARD_SIZE - 1 - col)
        crossDiagSum += weight;
    bool winnerFound = false;
    int winningSum = BOARD_SIZE * weight;
    if (rowSums[row] == winningSum ||
        colSums[col] == winningSum ||
        diagSum == winningSum ||
        crossDiagSum == winningSum)
    {
        winnerFound = true;
    }

    if (winnerFound)
    {
        setWinnerId(pId);
        setGameStatus(PLAYERWON);
    }
    else if (unoccupied == 0)
    {
        setGameStatus(gameState::TIED);
    }
}

bool Board::selectACell(int pId, int row, int col, cellSelectionErrorCodes &errorCode)
{
    if (row >= BOARD_SIZE || col >= BOARD_SIZE)
    {
        cout << "Invalid Cell, try again" << endl;
        errorCode = INVALID_CELL;
        return false;
    }
    if (pId <= 0)
    {
        cout << "playerId has to be greater than 0" << endl;
        errorCode = PLAYERID_INVALID;
        return false;
    }
    if (status != ONGOING)
    {
        cout << "Game already Over, no more selections!" << endl;
        errorCode = GAME_OVER;
        return false;
    }
    if (cells[row][col] == UNOCCUPIED)
    {
        unoccupied -= 1;
        cells[row][col] = pId;
        updateGameStatus(pId, row, col);
        return true;
    }
    else
    {
        errorCode = CELLOCCUPIED;
        cout << "Error in selecting the cell, row : " << row << ",col = " << col << " already selected" << endl;
        return false;
    }
}
gameState Board::getGameStatus()
{
    return status;
}
void Board::setGameStatus(gameState curStatus)
{
    status = curStatus;
}
int Board::getWinnerId()
{
    return winnerId;
}

void Board::setWinnerId(int pId)
{
    winnerId = pId;
}
void Board::resetBoard()
{
    unoccupied = BOARD_SIZE * BOARD_SIZE;
    winnerId = UNKNOWN;
    status = ONGOING;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        rowSums[i] = colSums[i] = 0;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cells[i][j] = UNOCCUPIED;
        }
    }
}
char Board::getSymbol(int playerId)
{
    if (playerId < 1)
        return ' ';
    return symbol[playerId - 1];
}
void Board::displayBoard()
{
    cout << "Current Board Status" << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << getSymbol(cells[i][j]) << "|";
        }
        cout << endl;
    }
}