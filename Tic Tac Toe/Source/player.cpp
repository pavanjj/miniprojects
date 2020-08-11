#include "../headers/player.h"
#include "../headers/generalUtils.h"
player ::player(int _id) : id(_id)
{
    fetchDetailsFromUser();
}

void player::fetchDetailsFromUser()
{
    cout << "Player Number " << getId() << ", please enter your name " << endl;
    cin >> name;
}

int player::getId()
{
    return id;
}
string player::getName()
{
    return name;
}

void player::updatePlayerStatus(playerState updatedStatus)
{
    playerStatus = updatedStatus;
}

playerState player::getPlayerStatus()
{
    return playerStatus;
}
std::pair<int, int> player::calcNextMove(const vector<vector<int>> &gameBoard)
{
    int row, col;
    cout << "Enter row-space-col of next move " << endl;
    cin >> row >> col;
    return std::make_pair(row - 1, col - 1);
}
std::pair<int, int> player::nextMove(const vector<vector<int>> &gameBoard)
{
    cout << getName() << " : Please Enter your selection " << endl;
    return calcNextMove(gameBoard);
}