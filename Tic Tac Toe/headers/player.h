
#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include <utility>
using namespace std;
#include "gameState.h"

class player
{
    string name;
    int id;
    playerState playerStatus;
    vector<int> moveHistory;
    void fetchDetailsFromUser();

public:
    player(int _id);
    int getId();
    string getName();
    std::pair<int, int> nextMove(const vector<vector<int>> &gameBoard);
    std::pair<int, int> calcNextMove(const vector<vector<int>> &gameBoard);
    void updatePlayerStatus(playerState updatedStatus);
    playerState getPlayerStatus();
};
#endif