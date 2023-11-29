#include "GameState.h"
#include <iostream>

using namespace std;

/*
Movestack& n1: trying to access the moveStack a private member variable so that all the functions in moveStack class can be accessed
the while loop will go on until the checkLastPLayerWIn gives a true boolean value;

*/

int main()
{

    GameState gameState;
    Movestack &n1 = gameState.getmoveStack();
    Move finalMove;

    string moves;
    while (!gameState.checkLastPlayerWin())
    {

        if (n1.getSize() == 9)
        {
            cout << "The game is draw!!!!";
            return 0;
        }

        gameState.displayBoardState(cout);
        cout << "Player " << gameState.getCurrentPlayer() << " make a turn!!" << endl;

        cin >> moves;

        if (moves == "Undo" || moves == "undo")
        {
            if (n1.isEmpty())
            {
                cout << "No moves to undo!" << endl;
            }
            else
            {
                gameState.undoLast();
            }
        }
        else if (moves == "quit")
        {
            return 0;
        }
        else if (moves == "move")
        {

            cin >> finalMove.x >> finalMove.y;

            if (gameState.addMove(finalMove) == 1)
            {
                if (gameState.checkLastPlayerWin() == true)
                {
                    gameState.displayBoardState(cout);
                    cout << "Player " << gameState.getCurrentPlayer() << " won !" << endl;

                    exit(1);
                }
                else
                {
                    n1.push(finalMove);
                }
            }
            else if (gameState.addMove(finalMove) == -1)
            {
                cout << "Incorrect move. Please try again." << endl;
                continue;
            }
        }
    }

    return 0;
}
