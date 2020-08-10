#define UNOCCUPIED -1

enum gameState
{
    PLAYERWON,
    ONGOING,
    TIED
};

enum playerState
{
    LOST,
    WON,
    PENDING,
    TIED
};
enum cellSelectionErrorCodes
{
    CELLOCCUPIED,
    PLAYERID_INVALID,
    GAME_OVER
};