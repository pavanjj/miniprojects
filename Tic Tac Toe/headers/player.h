#include <string>
#include <vector>
using namespace std;
enum status
{
    LOST,
    WON,
    PENDING,
    TIED
};

class player
{
    string name;
    int id;
    status playerStatus;
    vector<int> moveHistory;
    void fetchDetailsFromUser();

public:
    player(int _id);
    int getId();
    int nextMove(vector<vector<int>> &emptyCells);
    void updatePlayerStatus(const status &updatedStatus);
    status getPlayerStatus();
};