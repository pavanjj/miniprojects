#include <../headers/player.h>
#include <../headers/generalUtils.h>
using namespace std;
player ::player(int _id) : id(_id)
{
    fetchDetailsFromUser();
}

void player::fetchDetailsFromUser()
{
    printLine("Please Enter your name : ");
    cin >> name;
    printLine("Your Id is " + getId());
}

int player::getId()
{
    return id;
}

void player::updatePlayerStatus(const playerState &updatedStatus)
{
    playerStatus = updatedStatus;
}

playerState player::getPlayerStatus()
{
    return playerStatus;
}
pair<int, int> calcNextMove(const vector<vector<int>> &gameBoard)
{
}
pair<int, int> player::nextMove(const vector<vector<int>> &gameBoard)
{
    return calcNextMove(gameBoard);
}