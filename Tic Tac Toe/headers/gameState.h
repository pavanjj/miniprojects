#ifndef GAMESTATES
#define GAMESTATES
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
    DRAWN
};
enum cellSelectionErrorCodes
{
    CELLOCCUPIED,
    PLAYERID_INVALID,
    GAME_OVER,
    INVALID_CELL
};
#endif