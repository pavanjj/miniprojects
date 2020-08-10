#include <string>
#include <vector>
using namespace std;
#include <./gameState.h>

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
    pair<int, int> nextMove(const vector<vector<int>> &gameBoard);
    pair<int, int> calcNextMove(const vector<vector<int>> &gameBoard);
    void updatePlayerStatus(playerState updatedStatus);
    playerState getPlayerStatus();
};