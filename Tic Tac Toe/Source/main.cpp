using namespace std;
#include <../headers/player.h>
#include <iostream>
#include <gameController.h>
void main()
{
    cout << "Main method for Tic Tac Toe.. starting up" << endl;
    gameController ticTacToe;
    ticTacToe.initialise();
    ticTacToe.startGame();
    ticTacToe.displayResult();
}