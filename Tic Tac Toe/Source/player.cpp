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
pair<int, int> calcNextMove(const vector<vector<int>> &gameBoard)
{
    int row, col;
    cout << "Enter row of next move(0-based) " << endl;
    cin >> row;
    cout << "Enter col of next move (0-based)" << endl;
    cin >> col;
}
pair<int, int> player::nextMove(const vector<vector<int>> &gameBoard)
{
    return calcNextMove(gameBoard);
}