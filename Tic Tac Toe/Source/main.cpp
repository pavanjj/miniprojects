using namespace std;
#include <../headers/player.h>

void main()
{
    printLine("Main method for Tic Tac Toe.. starting up");
    //
    player p1();
    player p2();

    p2.getDetails();
    gameController.getGameSettings();
    gameController.initialize(p1, p2);
    gameController.startTheGame();
}