#include <iostream>
#include "TTTPlayer.hpp"
#include "TTTHumanPlayer.hpp"

TTTHumanPlayer::TTTHumanPlayer() {}

void TTTHumanPlayer::updateMove(int opponentBoard)
{
    int curBoard = myBoard | opponentBoard;
    int userIn = -1;
    bool validMove = false;

    while(!validMove)
    {
        int newPos;

        std::cout << "Input a move [1-9]: ";
        std::cin >> userIn;

        newPos = 1 << (userIn - 1);

        if(!(newPos & curBoard) && userIn > 0 && userIn < 10)
        {
            myBoard |= newPos;
            validMove = true;
        }
        else
            std::cout << "Invalid input." << std::endl;
    }

    return;
}