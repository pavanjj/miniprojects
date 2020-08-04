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
    cin << name;
    printLine("Your Id is " + getId());
}

int player::getId()
{
    return id;
}

void player::updatePlayerStatus(const status &updatedStatus)
{
    playerStatus = updatedStatus;
}

status player::getPlayerStatus()
{
    return playerStatus;
}

int player::nextMove(const vector<int> &emptyCells)
{
    calcNextMove(emptyCells);
}